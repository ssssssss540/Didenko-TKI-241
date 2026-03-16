#include <iostream>
#include <memory>
#include <vector>
#include "person.h"
#include "MedicalWorker.h"
#include "Patient.h"
#include "Room.h"
#include "Hospital.h"

void printSeparator() {
    std::cout << "--------------------------------------------------\n";    //
}

void printInfo(const std::vector<std::shared_ptr<Person>>& people) {
    for (const auto& person : people) {
        printSeparator();
        std::cout << "Тип: " << person->getType() << "\n";
        std::cout << person->getInfo() << "\n";
    }
    printSeparator();
}

void demonstrateHospitalFunctions(Hospital& hospital, int patient1Id, int patient2Id, int patient3Id,
                                  int doctor1Id, int doctor2Id, int nurseId) {
    std::cout << "\n ДЕМОНСТРАЦИЯ ФУНКЦИЙ БОЛЬНИЦЫ \n";

    printSeparator();
    std::cout << "1. Сведения о всех медицинских работниках:\n";
    auto allWorkers = hospital.getAllMedicalWorkers();
    for (const auto& worker : allWorkers) {
        std::cout << "- " << worker->getName()
                  << " (ID:" << worker->getId()
                  << ", " << worker->getSpecialization()
                  << ", " << worker->getDepartment() << ")\n";
    }

    printSeparator();
    std::cout << "2. Сведения о всех пациентах:\n";
    auto allPatients = hospital.getAllPatients();
    for (const auto& patient : allPatients) {
        std::cout << "- " << patient->getName()
                  << " (ID:" << patient->getId()
                  << ", Диагноз: " << patient->getDiagnosis()
                  << ", Палата: " << (patient->getRoom() ? patient->getRoom()->getRoomNumber() : "не назначена")
                  << ")\n";
    }

    printSeparator();
    std::cout << "3. Медицинские работники пациента P001 (теперь ID " << patient1Id << "):\n";
    auto doctorsForPatient = hospital.getMedicalWorkersForPatient(patient1Id);
    if (doctorsForPatient.empty()) {
        std::cout << "Для пациента не найдены медицинские работники\n";
    } else {
        for (const auto& doctor : doctorsForPatient) {
            std::cout << "- " << doctor->getName() << "\n";
        }
    }

    printSeparator();
    std::cout << "4. Пациенты медицинского работника W001 (теперь ID " << doctor1Id << "):\n";
    auto patientsForDoctor = hospital.getPatientsForMedicalWorker(doctor1Id);
    if (patientsForDoctor.empty()) {
        std::cout << "У медицинского работника нет пациентов\n";
    } else {
        for (const auto& patient : patientsForDoctor) {
            std::cout << "- " << patient->getName() << "\n";
        }
    }

    printSeparator();
    std::cout << "5. Пациенты в палате 101:\n";
    auto patientsInRoom = hospital.getPatientsInRoom("101");
    if (patientsInRoom.empty()) {
        std::cout << "В палате нет пациентов\n";
    } else {
        for (const auto& patient : patientsInRoom) {
            std::cout << "- " << patient->getName() << "\n";
        }
    }
}

int main() {
    std::cout << " СИСТЕМА УПРАВЛЕНИЯ БОЛЬНИЦЕЙ \n";

    std::vector<std::shared_ptr<Person>> people;

    auto doctor1 = std::make_shared<MedicalWorker>(
        "Иванов Иван Иванович", 45, "Терапевт", "Терапевтическое отделение");
    auto doctor2 = std::make_shared<MedicalWorker>(
        "Петрова Мария Сергеевна", 38, "Хирург", "Хирургическое отделение");
    auto nurse1 = std::make_shared<MedicalWorker>(
        "Сидорова Анна Петровна", 28, "Медсестра", "Терапевтическое отделение");

    auto room101 = std::make_shared<Room>("101");
    auto room102 = std::make_shared<Room>("102");

    auto patient1 = std::make_shared<Patient>(
        "Смирнов Алексей Владимирович", 35, "Грипп", "2024-01-15", room101);
    auto patient2 = std::make_shared<Patient>(
        "Козлова Елена Михайловна", 42, "Аппендицит", "2024-01-16", room102);
    auto patient3 = std::make_shared<Patient>(
        "Фёдоров Дмитрий Александрович", 50, "Гипертония", "2024-01-14", room101);

    people.push_back(doctor1);
    people.push_back(doctor2);
    people.push_back(nurse1);
    people.push_back(patient1);
    people.push_back(patient2);
    people.push_back(patient3);

    Hospital hospital;
    hospital.addMedicalWorker(doctor1);
    hospital.addMedicalWorker(doctor2);
    hospital.addMedicalWorker(nurse1);
    hospital.addPatient(patient1);
    hospital.addPatient(patient2);
    hospital.addPatient(patient3);

    hospital.assignPatientToDoctor(patient1->getId(), doctor1->getId());
    hospital.assignPatientToDoctor(patient2->getId(), doctor2->getId());
    hospital.assignPatientToDoctor(patient3->getId(), doctor1->getId());

    std::cout << "\nИТЕРАЦИЯ ПО КОЛЛЕКЦИИ ЛЮДЕЙ \n";
    printInfo(people);

    demonstrateHospitalFunctions(hospital,
                                 patient1->getId(), patient2->getId(), patient3->getId(),
                                 doctor1->getId(), doctor2->getId(), nurse1->getId());

    printSeparator();
    std::cout << "СТАТИСТИКА БОЛЬНИЦЫ:\n";
    std::cout << "Всего медицинских работников: " << hospital.getTotalMedicalWorkers() << "\n";
    std::cout << "Всего пациентов: " << hospital.getTotalPatients() << "\n";
    std::cout << "Всего отношений врач-пациент: " << hospital.getTotalRelations() << "\n";
    std::cout << "Всего назначений в палаты: " << hospital.getTotalRoomAssignments() << "\n";

    return 0;
}
