#include "test.h"
#include <vector>
#include <memory>

TEST_F(HospitalTests, MedicalWorkerCreation) {
    EXPECT_EQ(doctor->getName(), "Тестовый Врач");
    EXPECT_EQ(doctor->getAge(), 40);
    EXPECT_EQ(doctor->getSpecialization(), "Тестолог");
    EXPECT_EQ(doctor->getType(), "MedicalWorker");
}

TEST_F(HospitalTests, PatientCreation) {
    EXPECT_EQ(patient->getName(), "Тестовый Пациент");
    EXPECT_EQ(patient->getAge(), 30);
    EXPECT_EQ(patient->getDiagnosis(), "Тестовая болезнь");
    EXPECT_EQ(patient->getType(), "Patient");
}

TEST_F(HospitalTests, HospitalAddRemove) {
    EXPECT_EQ(hospital.getTotalMedicalWorkers(), 1);
    EXPECT_EQ(hospital.getTotalPatients(), 1);
    
    hospital.removeMedicalWorker("TEST001");
    EXPECT_EQ(hospital.getTotalMedicalWorkers(), 0);
    
    hospital.removePatient("TESTP001");
    EXPECT_EQ(hospital.getTotalPatients(), 0);
}

TEST_F(HospitalTests, DoctorPatientAssignment) {
    hospital.assignPatientToDoctor("TESTP001", "TEST001");
    
    auto patients = hospital.getPatientsForMedicalWorker("TEST001");
    EXPECT_EQ(patients.size(), 1);
    EXPECT_EQ(patients[0]->getId(), "TESTP001");
    
    auto doctors = hospital.getMedicalWorkersForPatient("TESTP001");
    EXPECT_EQ(doctors.size(), 1);
    EXPECT_EQ(doctors[0]->getId(), "TEST001");
}

TEST_F(HospitalTests, RoomPatients) {
    auto patient2 = std::make_shared<Patient>(
        "Второй Пациент", 25, "TESTP002",
        "Другая болезнь", "TEST-101", "2024-01-02");
    
    hospital.addPatient(patient2);
    
    auto patientsInRoom = hospital.getPatientsInRoom("TEST-101");
    EXPECT_EQ(patientsInRoom.size(), 2);
}

TEST_F(HospitalTests, PersonPolymorphism) {
    std::vector<std::shared_ptr<Person>> people;
    people.push_back(doctor);
    people.push_back(patient);
    
    EXPECT_EQ(people[0]->getType(), "MedicalWorker");
    EXPECT_EQ(people[1]->getType(), "Patient");
    
    EXPECT_FALSE(people[0]->getInfo().empty());
    EXPECT_FALSE(people[1]->getInfo().empty());
}

TEST_F(HospitalTests, StatisticsMethods) {
    EXPECT_EQ(hospital.getTotalMedicalWorkers(), 1);
    EXPECT_EQ(hospital.getTotalPatients(), 1);
    

    #ifdef HAS_RELATIONS_METHODS
    EXPECT_EQ(hospital.getTotalRelations(), 0);  
    EXPECT_EQ(hospital.getTotalRoomAssignments(), 1);  
    #endif
}

TEST_F(HospitalTests, RoomAssignmentMethods) {
    auto patientsInRoom = hospital.getPatientsInRoom("TEST-101");
    EXPECT_EQ(patientsInRoom.size(), 1);
    
    #ifdef HAS_CHANGE_ROOM_METHOD
    hospital.changePatientRoom("TESTP001", "TEST-102");
    patientsInRoom = hospital.getPatientsInRoom("TEST-101");
    EXPECT_EQ(patientsInRoom.size(), 0);
    
    patientsInRoom = hospital.getPatientsInRoom("TEST-102");
    EXPECT_EQ(patientsInRoom.size(), 1);
    #endif
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}