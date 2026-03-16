#include "MedicalWorker.h"
#include <sstream>
#include <algorithm>

MedicalWorker::MedicalWorker(const std::string& name, int age,
                             const std::string& specialization, const std::string& department)
    : Person(name, age), specialization(specialization), department(department) {}

std::string MedicalWorker::getInfo() const {
    std::stringstream ss;
    ss << "Медицинский работник: " << name
       << "\nВозраст: " << age
       << "\nID: " << id
       << "\nСпециализация: " << specialization
       << "\nОтделение: " << department
       << "\nКоличество пациентов: " << patients.size();  //
    return ss.str();
}

std::string MedicalWorker::getType() const { return "MedicalWorker"; }

std::string MedicalWorker::getSpecialization() const { return specialization; }
std::string MedicalWorker::getDepartment() const { return department; }

void MedicalWorker::setSpecialization(const std::string& specialization) { this->specialization = specialization; }
void MedicalWorker::setDepartment(const std::string& department) { this->department = department; }

void MedicalWorker::addPatient(const std::shared_ptr<Patient>& patient) {
    patients.push_back(patient);
}

void MedicalWorker::removePatient(int patientId) {
    patients.erase(std::remove_if(patients.begin(), patients.end(),
        [patientId](const auto& p) { return p->getId() == patientId; }),
        patients.end());
}

std::vector<std::shared_ptr<Patient>> MedicalWorker::getPatients() const {
    return patients;
}

bool MedicalWorker::hasPatient(int patientId) const {
    return std::any_of(patients.begin(), patients.end(),
        [patientId](const auto& p) { return p->getId() == patientId; });
}
