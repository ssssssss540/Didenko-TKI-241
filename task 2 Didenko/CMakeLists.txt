cmake_minimum_required(VERSION 3.14)
project(HospitalSolution)

set(CMAKE_CXX_STANDARD 17)


add_library(EntitiesLibrary STATIC
    Entities/Person.cpp
    Entities/MedicalWorker.cpp
    Entities/Patient.cpp
)


add_library(RelationsLibrary STATIC
    Relations/DoctorPatientRelation.cpp
    Relations/RoomAssignment.cpp
)


add_library(ManagementLibrary STATIC
    Management/Hospital.cpp
)


add_executable(HospitalApp HospitalApp/main.cpp)
target_link_libraries(HospitalApp 
    EntitiesLibrary 
    RelationsLibrary 
    ManagementLibrary
)


find_package(GTest REQUIRED)
add_executable(HospitalTests HospitalTests/Tests.cpp)
target_link_libraries(HospitalTests 
    EntitiesLibrary 
    RelationsLibrary 
    ManagementLibrary 
    GTest::gtest 
    GTest::gtest_main
)