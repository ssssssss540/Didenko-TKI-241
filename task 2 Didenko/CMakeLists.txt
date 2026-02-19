cmake_minimum_required(VERSION 3.14)
project(HospitalSolution)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SRC
    lib/Person.cpp
    lib/MedicalWorker.cpp
    lib/Patient.cpp
    lib/Room.cpp
    lib/Hospital.cpp
)

set(LIB_HEADERS
    lib/person.h
    lib/MedicalWorker.h
    lib/Patient.h
    lib/Room.h
    lib/Hospital.h
)

add_library(EntitiesLibrary STATIC ${LIB_SRC})

target_include_directories(EntitiesLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(HospitalApp app/main.cpp)
target_link_libraries(HospitalApp EntitiesLibrary)
target_include_directories(HospitalApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

find_package(GTest REQUIRED)

add_executable(HospitalTests test/test.cpp)
target_link_libraries(HospitalTests
    EntitiesLibrary
    GTest::gtest
    GTest::gtest_main
)
target_include_directories(HospitalTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

include(GoogleTest)
gtest_discover_tests(HospitalTests)