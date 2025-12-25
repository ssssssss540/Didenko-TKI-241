#include "RoomAssignment.h"

RoomAssignment::RoomAssignment(
    const std::shared_ptr<Patient>& patient,
    const std::string& roomNumber)
    : patient(patient), roomNumber(roomNumber) {}

std::shared_ptr<Patient> RoomAssignment::getPatient() const {
    return patient;
}

std::string RoomAssignment::getRoomNumber() const {
    return roomNumber;
}

bool RoomAssignment::isInRoom(const std::string& room) const {
    return roomNumber == room;
}

bool RoomAssignment::involvesPatient(const std::string& patientId) const {
    return patient && patient->getId() == patientId;
}

std::vector<std::shared_ptr<Patient>> 
RoomAssignment::getPatientsInRoom(
    const std::vector<std::shared_ptr<RoomAssignment>>& assignments,
    const std::string& roomNumber) {
    
    std::vector<std::shared_ptr<Patient>> result;
    for (const auto& assignment : assignments) {
        if (assignment->isInRoom(roomNumber)) {
            result.push_back(assignment->getPatient());
        }
    }
    return result;
}

std::shared_ptr<RoomAssignment> 
RoomAssignment::findAssignmentByPatient(
    const std::vector<std::shared_ptr<RoomAssignment>>& assignments,
    const std::string& patientId) {
    
    for (const auto& assignment : assignments) {
        if (assignment->involvesPatient(patientId)) {
            return assignment;
        }
    }
    return nullptr;
}