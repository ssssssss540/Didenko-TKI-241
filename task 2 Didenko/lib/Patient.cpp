#include "Patient.h"
#include "MedicalWorker.h"
#include <sstream>

Patient::Patient(const std::string& name, int age,
                 const std::string& diagnosis, const std::string& admissionDate,
                 std::shared_ptr<Room> room)
    : Person(name, age), diagnosis(diagnosis), room(room),
      admissionDate(admissionDate), attendingDoctor(nullptr) {}

std::string Patient::getInfo() const {
    std::stringstream ss;
    ss << "Пациент: " << name
       << "\nВозраст: " << age
       << "\nID: " << id
       << "\nДиагноз: " << diagnosis
       << "\nПалата: " << (room ? room->getRoomNumber() : "не назначена")
       << "\nДата поступления: " << admissionDate;
    if (attendingDoctor) {
        ss << "\nЛечащий врач: " << attendingDoctor->getName();
    } else {
        ss << "\nЛечащий врач: не назначен";
    }
    return ss.str();
}

std::string Patient::getType() const { return "Patient"; }

std::string Patient::getDiagnosis() const { return diagnosis; }
std::shared_ptr<Room> Patient::getRoom() const { return room; }
std::string Patient::getAdmissionDate() const { return admissionDate; }
std::shared_ptr<MedicalWorker> Patient::getAttendingDoctor() const { return attendingDoctor; }

void Patient::setDiagnosis(const std::string& diagnosis) { this->diagnosis = diagnosis; }
void Patient::setRoom(std::shared_ptr<Room> newRoom) { room = newRoom; }
void Patient::setAdmissionDate(const std::string& admissionDate) { this->admissionDate = admissionDate; }
void Patient::setAttendingDoctor(const std::shared_ptr<MedicalWorker>& doctor) { attendingDoctor = doctor; }

bool Patient::isInRoom(const std::shared_ptr<Room>& someRoom) const {
    return room == someRoom; 
}
