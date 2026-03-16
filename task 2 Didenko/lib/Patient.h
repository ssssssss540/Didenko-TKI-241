#pragma once
#include "person.h"
#include "Room.h"
#include <memory>

class MedicalWorker;   

class Patient : public Person {
private:
    std::string diagnosis;
    std::shared_ptr<Room> room;                
    std::string admissionDate;
    std::shared_ptr<MedicalWorker> attendingDoctor;

public:
    Patient(const std::string& name, int age,
            const std::string& diagnosis, const std::string& admissionDate,
            std::shared_ptr<Room> room = nullptr);

    std::string getInfo() const override;
    std::string getType() const override;   //
 
    std::string getDiagnosis() const;
    std::shared_ptr<Room> getRoom() const;      
    std::string getAdmissionDate() const;
    std::shared_ptr<MedicalWorker> getAttendingDoctor() const;

    void setDiagnosis(const std::string& diagnosis);
    void setRoom(std::shared_ptr<Room> newRoom); 
    void setAdmissionDate(const std::string& admissionDate);
    void setAttendingDoctor(const std::shared_ptr<MedicalWorker>& doctor);

    bool isInRoom(const std::shared_ptr<Room>& someRoom) const;
};
