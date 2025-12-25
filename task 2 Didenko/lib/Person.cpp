#include "person.h"

Person::Person(const std::string& name, int age, const std::string& id)
    : name(name), age(age), id(id) {}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

std::string Person::getId() const {
    return id;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}