#pragma once
#include <vector>
#include <memory>
#include <string>
#include "MedicalWorker.h"
#include "Patient.h"
#include "Room.h"

class Hospital {
private:
    std::vector<std::shared_ptr<MedicalWorker>> medicalWorkers;
    std::vector<std::shared_ptr<Patient>> patients;   
    std::vector<std::shared_ptr<Room>> rooms;          

public:
    Hospital() = default;

    void addMedicalWorker(const std::shared_ptr<MedicalWorker>& worker);
    void removeMedicalWorker(int workerId);
    std::shared_ptr<MedicalWorker> findMedicalWorker(int workerId) const;
    std::vector<std::shared_ptr<MedicalWorker>> getAllMedicalWorkers() const;

    void addPatient(const std::shared_ptr<Patient>& patient);
    void removePatient(int patientId);
    std::shared_ptr<Patient> findPatient(int patientId) const;
    std::vector<std::shared_ptr<Patient>> getAllPatients() const;

    void assignPatientToDoctor(int patientId, int doctorId);
    void removePatientFromDoctor(int patientId, int doctorId);
    std::vector<std::shared_ptr<MedicalWorker>> getMedicalWorkersForPatient(int patientId) const;
    std::vector<std::shared_ptr<Patient>> getPatientsForMedicalWorker(int workerId) const;

    
    std::shared_ptr<Room> findOrCreateRoom(const std::string& roomNumber); 
    void assignPatientToRoom(int patientId, const std::string& roomNumber);
    void changePatientRoom(int patientId, const std::string& newRoomNumber);
    std::vector<std::shared_ptr<Patient>> getPatientsInRoom(const std::string& roomNumber) const;

    
    int getTotalMedicalWorkers() const;
    int getTotalPatients() const;
    int getTotalRelations() const;          
    int getTotalRoomAssignments() const;    
};
