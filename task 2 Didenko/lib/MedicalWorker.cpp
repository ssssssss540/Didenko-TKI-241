#include "MedicalWorker.h"
#include <sstream>

MedicalWorker::MedicalWorker(const std::string& name, int age, const std::string& id,
                             const std::string& specialization, const std::string& department)
    : Person(name, age, id), specialization(specialization), department(department) {}

std::string MedicalWorker::getInfo() const {
    std::stringstream ss;
    ss << "Медицинский работник: " << name 
       << "\nВозраст: " << age 
       << "\nID: " << id
       << "\nСпециализация: " << specialization
       << "\nОтделение: " << department
       << "\nКоличество пациентов: " << patients.size();
    return ss.str();
}

std::string MedicalWorker::getType() const {
    return "MedicalWorker";
}

std::string MedicalWorker::getSpecialization() const {
    return specialization;
}

std::string MedicalWorker::getDepartment() const {
    return department;
}

void MedicalWorker::setSpecialization(const std::string& specialization) {
    this->specialization = specialization;
}

void MedicalWorker::setDepartment(const std::string& department) {
    this->department = department;
}

void MedicalWorker::addPatient(const std::shared_ptr<Patient>& patient) {
    patients.push_back(patient);
}

void MedicalWorker::removePatient(const std::string& patientId) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if ((*it)->getId() == patientId) {
            patients.erase(it);
            break;
        }
    }
}

std::vector<std::shared_ptr<Patient>> MedicalWorker::getPatients() const {
    return patients;
}

bool MedicalWorker::hasPatient(const std::string& patientId) const {
    for (const auto& patient : patients) {
        if (patient->getId() == patientId) {
            return true;
        }
    }
    return false;
}