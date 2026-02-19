#pragma once
#include "person.h"
#include "Patient.h"
#include <vector>
#include <memory>

class MedicalWorker : public Person {
private:
    std::string specialization;
    std::string department;
    std::vector<std::shared_ptr<Patient>> patients;

public:
    MedicalWorker(const std::string& name, int age,
                  const std::string& specialization, const std::string& department);

    std::string getInfo() const override;
    std::string getType() const override;

    std::string getSpecialization() const;
    std::string getDepartment() const;

    void setSpecialization(const std::string& specialization);
    void setDepartment(const std::string& department);

    void addPatient(const std::shared_ptr<Patient>& patient);
    void removePatient(int patientId);                // только одна версия
    std::vector<std::shared_ptr<Patient>> getPatients() const;
    bool hasPatient(int patientId) const;
};