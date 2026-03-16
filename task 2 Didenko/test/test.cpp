#include "test.h"
#include <vector>
#include <memory>

TEST_F(HospitalTests, MedicalWorkerCreation) {
    EXPECT_EQ(doctor->getName(), "Тестовый Врач");
    EXPECT_EQ(doctor->getAge(), 40);
    EXPECT_EQ(doctor->getSpecialization(), "Тестолог");
    EXPECT_EQ(doctor->getType(), "MedicalWorker");
    EXPECT_GT(doctor->getId(), 0); 
}

TEST_F(HospitalTests, PatientCreation) {
    EXPECT_EQ(patient->getName(), "Тестовый Пациент");
    EXPECT_EQ(patient->getAge(), 30);
    EXPECT_EQ(patient->getDiagnosis(), "Тестовая болезнь");
    EXPECT_EQ(patient->getType(), "Patient"); //
    EXPECT_GT(patient->getId(), 0);
}

TEST_F(HospitalTests, HospitalAddRemove) {
    EXPECT_EQ(hospital.getTotalMedicalWorkers(), 1);
    EXPECT_EQ(hospital.getTotalPatients(), 1);

    hospital.removeMedicalWorker(doctor->getId());
    EXPECT_EQ(hospital.getTotalMedicalWorkers(), 0);

    hospital.removePatient(patient->getId());
    EXPECT_EQ(hospital.getTotalPatients(), 0);
}

TEST_F(HospitalTests, DoctorPatientAssignment) {
    hospital.assignPatientToDoctor(patient->getId(), doctor->getId());

    auto patients = hospital.getPatientsForMedicalWorker(doctor->getId());
    EXPECT_EQ(patients.size(), 1);
    EXPECT_EQ(patients[0]->getId(), patient->getId());

    auto doctors = hospital.getMedicalWorkersForPatient(patient->getId());
    EXPECT_EQ(doctors.size(), 1);
    EXPECT_EQ(doctors[0]->getId(), doctor->getId());
}

TEST_F(HospitalTests, RoomPatients) {
    auto room = std::make_shared<Room>("TEST-101");
    auto patient2 = std::make_shared<Patient>(
        "Второй Пациент", 25, "Другая болезнь", "2024-01-02", room);
    hospital.addPatient(patient2);
    hospital.assignPatientToRoom(patient->getId(), "TEST-101"); 

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
    EXPECT_EQ(hospital.getTotalRelations(), 0);
    EXPECT_EQ(hospital.getTotalRoomAssignments(), 0); 
}

TEST_F(HospitalTests, RoomAssignmentMethods) {
    hospital.assignPatientToRoom(patient->getId(), "TEST-101");
    auto patientsInRoom = hospital.getPatientsInRoom("TEST-101");
    EXPECT_EQ(patientsInRoom.size(), 1);

    hospital.changePatientRoom(patient->getId(), "TEST-102");
    patientsInRoom = hospital.getPatientsInRoom("TEST-101");
    EXPECT_EQ(patientsInRoom.size(), 0);

    patientsInRoom = hospital.getPatientsInRoom("TEST-102");
    EXPECT_EQ(patientsInRoom.size(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
