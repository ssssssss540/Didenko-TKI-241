#pragma once
#include <string>

class Room {
private:
    std::string roomNumber;
public:
    Room(const std::string& number);
    std::string getRoomNumber() const;   //
};
