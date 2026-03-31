#pragma once
#include <vector>
#include <memory>
#include <string>
#include "MedicalWorker.h"
#include "Patient.h"
#include "DoctorPatientRelation.h"
#include "RoomAssignment.h"

class Hospital {
private:
    std::vector<std::shared_ptr<MedicalWorker>> medicalWorkers;
    std::vector<std::shared_ptr<Patient>> patients;
    
    std::vector<std::shared_ptr<DoctorPatientRelation>> doctorPatientRelations;
    std::vector<std::shared_ptr<RoomAssignment>> roomAssignments;

public:
    Hospital() = default;
    
    void addMedicalWorker(const std::shared_ptr<MedicalWorker>& worker);
    void removeMedicalWorker(const std::string& workerId);
    std::shared_ptr<MedicalWorker> findMedicalWorker(const std::string& workerId) const;
    std::vector<std::shared_ptr<MedicalWorker>> getAllMedicalWorkers() const;
    
    void addPatient(const std::shared_ptr<Patient>& patient);
    void removePatient(const std::string& patientId);
    std::shared_ptr<Patient> findPatient(const std::string& patientId) const;
    std::vector<std::shared_ptr<Patient>> getAllPatients() const;
    
    void assignPatientToDoctor(const std::string& patientId, 
                               const std::string& doctorId);
    void removePatientFromDoctor(const std::string& patientId, 
                                 const std::string& doctorId);
    std::vector<std::shared_ptr<MedicalWorker>> getMedicalWorkersForPatient(
        const std::string& patientId) const;
    std::vector<std::shared_ptr<Patient>> getPatientsForMedicalWorker(
        const std::string& workerId) const;
    
    void assignPatientToRoom(const std::string& patientId, 
                             const std::string& roomNumber);
    void changePatientRoom(const std::string& patientId, 
                           const std::string& newRoomNumber);
    void removePatientFromRoom(const std::string& patientId);  // ДОБАВЛЕН ЭТОТ МЕТОД
    
    std::vector<std::shared_ptr<Patient>> getPatientsInRoom(
        const std::string& roomNumber) const;
    
    int getTotalMedicalWorkers() const;
    int getTotalPatients() const;
    int getTotalRelations() const;
    int getTotalRoomAssignments() const;
};