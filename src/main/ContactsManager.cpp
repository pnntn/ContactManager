#include "../headers/ContactsManager.h"
#include <iostream>
#include <algorithm>

void ContactsManager::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void ContactsManager::displayContacts() const {
    std::cout << "Contacts:\n";
    for (std::vector<Contact>::const_iterator it = contacts.begin(); it != contacts.end(); ++it) {
        std::cout << "Name: " << it->getName() << ", Phone: " << it->getPhoneNumber() << std::endl;
    }
}

void ContactsManager::searchContact(const std::string& name) const {
    std::vector<Contact>::const_iterator it;
    for (it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getName() == name) {
            std::cout << "Contact found: Name: " << it->getName() << ", Phone: " << it->getPhoneNumber() << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

void ContactsManager::updateContact(const std::string& name) {
    std::vector<Contact>::iterator it;
    for (it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getName() == name) {
            std::string newName, newPhoneNumber;
            std::cout << "Enter new name: ";
            std::cin >> newName;
            std::cout << "Enter new phone number: ";
            std::cin >> newPhoneNumber;
            it->setName(newName);
            it->setPhoneNumber(newPhoneNumber);
            std::cout << "Contact updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

void ContactsManager::deleteContact(const std::string& name) {
    std::vector<Contact>::iterator it;
    for (it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getName() == name) {
            contacts.erase(it);
            std::cout << "Contact deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}
