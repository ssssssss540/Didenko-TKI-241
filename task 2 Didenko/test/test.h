#pragma once
#include <gtest/gtest.h>
#include <memory>
#include "MedicalWorker.h"
#include "Patient.h"
#include "Person.h"  
#include "Hospital.h"

class HospitalTests : public ::testing::Test {
protected:
    void SetUp() override {
        doctor = std::make_shared<MedicalWorker>(
            "Тестовый Врач", 40, "TEST001", 
            "Тестолог", "Тестовое отделение");
        
        patient = std::make_shared<Patient>(
            "Тестовый Пациент", 30, "TESTP001",
            "Тестовая болезнь", "TEST-101", "2024-01-01");
        
        hospital.addMedicalWorker(doctor);
        hospital.addPatient(patient);
    }
    
    void TearDown() override {
    }
    
    Hospital hospital;
    std::shared_ptr<MedicalWorker> doctor;
    std::shared_ptr<Patient> patient;
};