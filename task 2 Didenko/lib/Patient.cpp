#include "Patient.h"
#include "MedicalWorker.h"
#include <sstream>

Patient::Patient(const std::string& name, int age, const std::string& id,
                 const std::string& diagnosis, const std::string& roomNumber,
                 const std::string& admissionDate)
    : Person(name, age, id), diagnosis(diagnosis), 
      roomNumber(roomNumber), admissionDate(admissionDate), attendingDoctor(nullptr) {}

std::string Patient::getInfo() const {
    std::stringstream ss;
    ss << "Пациент: " << name
       << "\nВозраст: " << age
       << "\nID: " << id
       << "\nДиагноз: " << diagnosis
       << "\nПалата: " << roomNumber
       << "\nДата поступления: " << admissionDate;
    
    if (attendingDoctor) {
        ss << "\nЛечащий врач: " << attendingDoctor->getName();
    } else {
        ss << "\nЛечащий врач: не назначен";
    }
    
    return ss.str();
}

std::string Patient::getType() const {
    return "Patient";
}

std::string Patient::getDiagnosis() const {
    return diagnosis;
}

std::string Patient::getRoomNumber() const {
    return roomNumber;
}

std::string Patient::getAdmissionDate() const {
    return admissionDate;
}

std::shared_ptr<MedicalWorker> Patient::getAttendingDoctor() const {
    return attendingDoctor;
}

void Patient::setDiagnosis(const std::string& diagnosis) {
    this->diagnosis = diagnosis;
}

void Patient::setRoomNumber(const std::string& roomNumber) {
    this->roomNumber = roomNumber;
}

void Patient::setAdmissionDate(const std::string& admissionDate) {
    this->admissionDate = admissionDate;
}

void Patient::setAttendingDoctor(const std::shared_ptr<MedicalWorker>& doctor) {
    this->attendingDoctor = doctor;
}

bool Patient::isInRoom(const std::string& room) const {
    return roomNumber == room;
}