#include "Room.h"

Room::Room(const std::string& number) : roomNumber(number) {}
std::string Room::getRoomNumber() const { return roomNumber; } //
