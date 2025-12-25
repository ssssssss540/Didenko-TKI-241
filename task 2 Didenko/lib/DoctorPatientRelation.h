#pragma once
#include <memory>
#include <vector>
#include <string>
#include "MedicalWorker.h"
#include "Patient.h"

class DoctorPatientRelation {
private:
    std::shared_ptr<MedicalWorker> doctor;
    std::shared_ptr<Patient> patient;
    
public:
    DoctorPatientRelation(
        const std::shared_ptr<MedicalWorker>& doctor,
        const std::shared_ptr<Patient>& patient);
    
    std::shared_ptr<MedicalWorker> getDoctor() const;
    std::shared_ptr<Patient> getPatient() const;
    
    bool involvesDoctor(const std::string& doctorId) const;
    bool involvesPatient(const std::string& patientId) const;
    
    static std::vector<std::shared_ptr<DoctorPatientRelation>> 
        findRelationsByDoctor(
            const std::vector<std::shared_ptr<DoctorPatientRelation>>& relations,
            const std::string& doctorId);
    
    static std::vector<std::shared_ptr<DoctorPatientRelation>> 
        findRelationsByPatient(
            const std::vector<std::shared_ptr<DoctorPatientRelation>>& relations,
            const std::string& patientId);
};