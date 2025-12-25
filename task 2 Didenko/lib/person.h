#pragma once
#include <string>
#include <memory>

class Person {
protected:
    std::string name;
    int age;
    std::string id;// static int

public:
    Person(const std::string& name, int age, const std::string& id);
    virtual ~Person() = default;
    
    virtual std::string getInfo() const = 0;
    virtual std::string getType() const = 0;
    
    std::string getName() const;
    int getAge() const;
    std::string getId() const;
    
    void setName(const std::string& name);
    void setAge(int age);
};
