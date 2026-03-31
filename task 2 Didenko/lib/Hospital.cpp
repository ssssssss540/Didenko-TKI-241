#include "Hospital.h"
#include <algorithm>

void Hospital::addMedicalWorker(const std::shared_ptr<MedicalWorker>& worker) {
    if (!worker || findMedicalWorker(worker->getId())) {
        return;
    }
    medicalWorkers.push_back(worker);
}

void Hospital::removeMedicalWorker(const std::string& workerId) {
    auto it = std::remove_if(medicalWorkers.begin(), medicalWorkers.end(),
        [&workerId](const auto& worker) {
            return worker->getId() == workerId;
        });
    medicalWorkers.erase(it, medicalWorkers.end());
    
    auto it2 = std::remove_if(doctorPatientRelations.begin(), doctorPatientRelations.end(),
        [&workerId](const auto& relation) {
            return relation->involvesDoctor(workerId);
        });
    doctorPatientRelations.erase(it2, doctorPatientRelations.end());
}

std::shared_ptr<MedicalWorker> Hospital::findMedicalWorker(const std::string& workerId) const {
    for (const auto& worker : medicalWorkers) {
        if (worker->getId() == workerId) {
            return worker;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<MedicalWorker>> Hospital::getAllMedicalWorkers() const {
    return medicalWorkers;
}

void Hospital::addPatient(const std::shared_ptr<Patient>& patient) {
    if (!patient || findPatient(patient->getId())) {
        return;
    }
    patients.push_back(patient);
    
    roomAssignments.push_back(
        std::make_shared<RoomAssignment>(patient, patient->getRoomNumber())
    );
}

void Hospital::removePatient(const std::string& patientId) {
    auto it = std::remove_if(patients.begin(), patients.end(),
        [&patientId](const auto& patient) {
            return patient->getId() == patientId;
        });
    patients.erase(it, patients.end());
    
    auto it2 = std::remove_if(doctorPatientRelations.begin(), doctorPatientRelations.end(),
        [&patientId](const auto& relation) {
            return relation->involvesPatient(patientId);
        });
    doctorPatientRelations.erase(it2, doctorPatientRelations.end());
    
    removePatientFromRoom(patientId);  
}

std::shared_ptr<Patient> Hospital::findPatient(const std::string& patientId) const {
    for (const auto& patient : patients) {
        if (patient->getId() == patientId) {
            return patient;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Patient>> Hospital::getAllPatients() const {
    return patients;
}

void Hospital::assignPatientToDoctor(const std::string& patientId, 
                                     const std::string& doctorId) {
    auto patient = findPatient(patientId);
    auto doctor = findMedicalWorker(doctorId);
    
    if (!patient || !doctor) {
        return;
    }
    
    for (const auto& relation : doctorPatientRelations) {
        if (relation->involvesPatient(patientId) && 
            relation->involvesDoctor(doctorId)) {
            return; 
        }
    }
    
    doctorPatientRelations.push_back(
        std::make_shared<DoctorPatientRelation>(doctor, patient)
    );
    
    patient->setAttendingDoctor(doctor);
    doctor->addPatient(patient);
}

void Hospital::removePatientFromDoctor(const std::string& patientId, 
                                       const std::string& doctorId) {
    auto it = std::remove_if(doctorPatientRelations.begin(), doctorPatientRelations.end(),
        [&patientId, &doctorId](const auto& relation) {
            return relation->involvesPatient(patientId) && 
                   relation->involvesDoctor(doctorId);
        });
    doctorPatientRelations.erase(it, doctorPatientRelations.end());
    
    auto patient = findPatient(patientId);
    auto doctor = findMedicalWorker(doctorId);
    
    if (patient && doctor) {
        doctor->removePatient(patientId);
        patient->setAttendingDoctor(nullptr);
    }
}

std::vector<std::shared_ptr<MedicalWorker>> Hospital::getMedicalWorkersForPatient(
    const std::string& patientId) const {
    
    std::vector<std::shared_ptr<MedicalWorker>> result;
    for (const auto& relation : doctorPatientRelations) {
        if (relation->involvesPatient(patientId)) {
            result.push_back(relation->getDoctor());
        }
    }
    
    return result;
}

std::vector<std::shared_ptr<Patient>> Hospital::getPatientsForMedicalWorker(
    const std::string& workerId) const {
    
    std::vector<std::shared_ptr<Patient>> result;
    for (const auto& relation : doctorPatientRelations) {
        if (relation->involvesDoctor(workerId)) {
            result.push_back(relation->getPatient());
        }
    }
    
    return result;
}

void Hospital::assignPatientToRoom(const std::string& patientId, 
                                   const std::string& roomNumber) {
    auto patient = findPatient(patientId);
    if (!patient) {
        return;
    }
    
    patient->setRoomNumber(roomNumber);
    
    bool assignmentFound = false;
    for (auto& assignment : roomAssignments) {
        if (assignment->involvesPatient(patientId)) {
            assignment = std::make_shared<RoomAssignment>(patient, roomNumber);
            assignmentFound = true;
            break;
        }
    }
    
    if (!assignmentFound) {
        roomAssignments.push_back(
            std::make_shared<RoomAssignment>(patient, roomNumber)
        );
    }
}

void Hospital::changePatientRoom(const std::string& patientId, 
                                 const std::string& newRoomNumber) {
    assignPatientToRoom(patientId, newRoomNumber);
}

void Hospital::removePatientFromRoom(const std::string& patientId) {
    auto it = std::remove_if(roomAssignments.begin(), roomAssignments.end(),
        [&patientId](const auto& assignment) {
            return assignment->involvesPatient(patientId);
        });
    roomAssignments.erase(it, roomAssignments.end());
}

std::vector<std::shared_ptr<Patient>> Hospital::getPatientsInRoom(
    const std::string& roomNumber) const {
    
    std::vector<std::shared_ptr<Patient>> result;
    for (const auto& assignment : roomAssignments) {
        if (assignment->isInRoom(roomNumber)) {
            result.push_back(assignment->getPatient());
        }
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
    return static_cast<int>(doctorPatientRelations.size());
}

int Hospital::getTotalRoomAssignments() const {
    return static_cast<int>(roomAssignments.size());
}