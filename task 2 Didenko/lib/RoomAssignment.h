#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Patient.h"

class RoomAssignment {
private:
    std::shared_ptr<Patient> patient;
    std::string roomNumber;
    
public:
    RoomAssignment(
        const std::shared_ptr<Patient>& patient,
        const std::string& roomNumber);
    
    std::shared_ptr<Patient> getPatient() const;
    std::string getRoomNumber() const;
    
    bool isInRoom(const std::string& room) const;
    bool involvesPatient(const std::string& patientId) const;
    
    static std::vector<std::shared_ptr<Patient>> 
        getPatientsInRoom(
            const std::vector<std::shared_ptr<RoomAssignment>>& assignments,
            const std::string& roomNumber);
    
    static std::shared_ptr<RoomAssignment> 
        findAssignmentByPatient(
            const std::vector<std::shared_ptr<RoomAssignment>>& assignments,
            const std::string& patientId);
};