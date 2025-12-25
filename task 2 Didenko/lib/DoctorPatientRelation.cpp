#include "DoctorPatientRelation.h"

DoctorPatientRelation::DoctorPatientRelation(
    const std::shared_ptr<MedicalWorker>& doctor,
    const std::shared_ptr<Patient>& patient)
    : doctor(doctor), patient(patient) {}

std::shared_ptr<MedicalWorker> DoctorPatientRelation::getDoctor() const {
    return doctor;
}

std::shared_ptr<Patient> DoctorPatientRelation::getPatient() const {
    return patient;
}

bool DoctorPatientRelation::involvesDoctor(const std::string& doctorId) const {
    return doctor && doctor->getId() == doctorId;
}

bool DoctorPatientRelation::involvesPatient(const std::string& patientId) const {
    return patient && patient->getId() == patientId;
}

std::vector<std::shared_ptr<DoctorPatientRelation>> 
DoctorPatientRelation::findRelationsByDoctor(
    const std::vector<std::shared_ptr<DoctorPatientRelation>>& relations,
    const std::string& doctorId) {
    
    std::vector<std::shared_ptr<DoctorPatientRelation>> result;
    for (const auto& relation : relations) {
        if (relation->involvesDoctor(doctorId)) {
            result.push_back(relation);
        }
    }
    return result;
}

std::vector<std::shared_ptr<DoctorPatientRelation>> 
DoctorPatientRelation::findRelationsByPatient(
    const std::vector<std::shared_ptr<DoctorPatientRelation>>& relations,
    const std::string& patientId) {
    
    std::vector<std::shared_ptr<DoctorPatientRelation>> result;
    for (const auto& relation : relations) {
        if (relation->involvesPatient(patientId)) {
            result.push_back(relation);
        }
    }
    return result;
}