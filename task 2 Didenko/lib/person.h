#pragma once
#include <string>

class Person {
protected:
    std::string name;
    int age;
    int id;                     
    static int nextId;          

public:
    Person(const std::string& name, int age);
    virtual ~Person() = default;

    virtual std::string getInfo() const = 0;
    virtual std::string getType() const = 0;

    std::string getName() const;
    int getAge() const;
    int getId() const;          

    void setName(const std::string& name);
    void setAge(int age);
};