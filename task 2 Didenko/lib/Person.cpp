#include "person.h"

int Person::nextId = 1;         

Person::Person(const std::string& name, int age)
    : name(name), age(age), id(nextId++) {}

std::string Person::getName() const { return name; }
int Person::getAge() const { return age; }
int Person::getId() const { return id; }

void Person::setName(const std::string& name) { this->name = name; }
void Person::setAge(int age) { this->age = age; } //
