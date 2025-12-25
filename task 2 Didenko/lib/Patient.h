#pragma once
#include "person.h"
#include <string>
#include <memory>

class MedicalWorker;

class Patient : public Person {
private:
    std::string diagnosis;
    std::string roomNumber;
    std::string admissionDate;
    std::shared_ptr<MedicalWorker> attendingDoctor;

public:
    Patient(const std::string& name, int age, const std::string& id,
            const std::string& diagnosis, const std::string& roomNumber,
            const std::string& admissionDate);
    
    std::string getInfo() const override;
    std::string getType() const override;
    
    std::string getDiagnosis() const;
    std::string getRoomNumber() const;
    std::string getAdmissionDate() const;
    std::shared_ptr<MedicalWorker> getAttendingDoctor() const;
    
    void setDiagnosis(const std::string& diagnosis);
    void setRoomNumber(const std::string& roomNumber);
    void setAdmissionDate(const std::string& admissionDate);
    void setAttendingDoctor(const std::shared_ptr<MedicalWorker>& doctor);
    
    bool isInRoom(const std::string& room) const;
};