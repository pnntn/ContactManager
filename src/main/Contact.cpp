#include "../headers/Contact.h"

Contact::Contact(const std::string& name, const std::string& phoneNumber)
    : name(name), phoneNumber(phoneNumber) {}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}
