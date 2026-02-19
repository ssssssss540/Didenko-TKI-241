#include "Hospital.h"
#include <algorithm>

void Hospital::addMedicalWorker(const std::shared_ptr<MedicalWorker>& worker) {
    if (!worker || findMedicalWorker(worker->getId()))
        return;
    medicalWorkers.push_back(worker);
}

void Hospital::removeMedicalWorker(int workerId) {
    medicalWorkers.erase(std::remove_if(medicalWorkers.begin(), medicalWorkers.end(),
        [workerId](const auto& w) { return w->getId() == workerId; }),
        medicalWorkers.end());

    for (auto& p : patients) {
        if (p->getAttendingDoctor() && p->getAttendingDoctor()->getId() == workerId)
            p->setAttendingDoctor(nullptr);
    }
}

std::shared_ptr<MedicalWorker> Hospital::findMedicalWorker(int workerId) const {
    for (const auto& w : medicalWorkers)
        if (w->getId() == workerId)
            return w;
    return nullptr;
}

std::vector<std::shared_ptr<MedicalWorker>> Hospital::getAllMedicalWorkers() const {
    return medicalWorkers;
}

void Hospital::addPatient(const std::shared_ptr<Patient>& patient) {
    if (!patient || findPatient(patient->getId()))
        return;
    patients.push_back(patient);
}

void Hospital::removePatient(int patientId) {
    patients.erase(std::remove_if(patients.begin(), patients.end(),
        [patientId](const auto& p) { return p->getId() == patientId; }),
        patients.end());

    for (auto& w : medicalWorkers) {
        w->removePatient(patientId);
    }
}

std::shared_ptr<Patient> Hospital::findPatient(int patientId) const {
    for (const auto& p : patients)
        if (p->getId() == patientId)
            return p;
    return nullptr;
}

std::vector<std::shared_ptr<Patient>> Hospital::getAllPatients() const {
    return patients;
}

void Hospital::assignPatientToDoctor(int patientId, int doctorId) {
    auto patient = findPatient(patientId);
    auto doctor = findMedicalWorker(doctorId);
    if (!patient || !doctor)
        return;

    if (patient->getAttendingDoctor() && patient->getAttendingDoctor()->getId() == doctorId)
        return;
    if (doctor->hasPatient(patientId))
        return;

    if (auto oldDoctor = patient->getAttendingDoctor()) {
        oldDoctor->removePatient(patientId);
    }

    patient->setAttendingDoctor(doctor);
    doctor->addPatient(patient);
}

void Hospital::removePatientFromDoctor(int patientId, int doctorId) {
    auto patient = findPatient(patientId);
    auto doctor = findMedicalWorker(doctorId);
    if (!patient || !doctor)
        return;

    if (patient->getAttendingDoctor() && patient->getAttendingDoctor()->getId() == doctorId) {
        patient->setAttendingDoctor(nullptr);
        doctor->removePatient(patientId);
    }
}

std::vector<std::shared_ptr<MedicalWorker>> Hospital::getMedicalWorkersForPatient(int patientId) const {
    std::vector<std::shared_ptr<MedicalWorker>> result;
    auto patient = findPatient(patientId);
    if (patient && patient->getAttendingDoctor()) {
        result.push_back(patient->getAttendingDoctor());
    }
    return result;
}

std::vector<std::shared_ptr<Patient>> Hospital::getPatientsForMedicalWorker(int workerId) const {
    auto doctor = findMedicalWorker(workerId);
    if (doctor)
        return doctor->getPatients();
    return {};
}

std::shared_ptr<Room> Hospital::findOrCreateRoom(const std::string& roomNumber) {
    for (const auto& r : rooms) {
        if (r->getRoomNumber() == roomNumber)
            return r;
    }
    auto newRoom = std::make_shared<Room>(roomNumber);
    rooms.push_back(newRoom);
    return newRoom;
}

void Hospital::assignPatientToRoom(int patientId, const std::string& roomNumber) {
    auto patient = findPatient(patientId);
    if (!patient) return;

    auto room = findOrCreateRoom(roomNumber);
    patient->setRoom(room);
}

void Hospital::changePatientRoom(int patientId, const std::string& newRoomNumber) {
    assignPatientToRoom(patientId, newRoomNumber); 
}

std::vector<std::shared_ptr<Patient>> Hospital::getPatientsInRoom(const std::string& roomNumber) const {
    std::vector<std::shared_ptr<Patient>> result;
    auto room = std::find_if(rooms.begin(), rooms.end(),
        [&roomNumber](const auto& r) { return r->getRoomNumber() == roomNumber; });
    if (room == rooms.end()) return result;

    for (const auto& p : patients) {
        if (p->getRoom() == *room)
            result.push_back(p);
    }
    return result;
}

int Hospital::getTotalMedicalWorkers() const {
    return static_cast<int>(medicalWorkers.size());
}

int Hospital::getTotalPatients() const {
    return static_cast<int>(patients.size());
}

int Hospital::getTotalRelations() const {
    int count = 0;
    for (const auto& w : medicalWorkers) {
        count += w->getPatients().size();
    }
    return count;
}

int Hospital::getTotalRoomAssignments() const {
    int count = 0;
    for (const auto& p : patients) {
        if (p->getRoom() != nullptr)
            ++count;
    }
    return count;
}