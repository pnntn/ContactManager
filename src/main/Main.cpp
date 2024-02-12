#include <iostream>
#include <fstream>
#include <limits>
#include "../headers/Contact.h"
#include "../headers/ContactsManager.h"

const std::string FILE_NAME = "contacts.txt";

void loadContactsFromFile(ContactsManager& manager) {
    std::ifstream inputFile(FILE_NAME);
    if (inputFile.is_open()) {
        std::string name, phoneNumber;
        while (inputFile >> name >> phoneNumber) {
            Contact contact(name, phoneNumber);
            manager.addContact(contact);
        }
        inputFile.close();
    } else {
        std::cout << "File not found. Creating a new one.\n";
    }
}

void saveContactsToFile(const ContactsManager& manager) {
    std::ofstream outputFile(FILE_NAME);
    if (outputFile.is_open()) {
        for (const auto& contact : manager.getContacts()) {
            outputFile << contact.getName() << " " << contact.getPhoneNumber() << std::endl;
        }
        outputFile.close();
        std::cout << "Contact list updated.\n";
    } else {
        std::cout << "Unable to open file.\n";
    }
}

int main() {
    ContactsManager manager;
    loadContactsFromFile(manager);

    int choice;
    do {
        std::cout << "\nSelect an operation:\n";
        std::cout << "1. Add contact\n";
        std::cout << "2. Display contacts\n";
        std::cout << "3. Search contact\n";
        std::cout << "4. Update contact\n";
        std::cout << "5. Delete contact\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::string name;
        switch (choice) {
            case 1:
                {
                    std::string phoneNumber;
                    std::cout << "Enter the name of the contact: ";
                    std::cin >> name;
                    std::cout << "Enter the phone number of the contact: ";
                    std::cin >> phoneNumber;
                    Contact newContact(name, phoneNumber);
                    manager.addContact(newContact);
                    saveContactsToFile(manager);
                }
                break;
            case 2:
                manager.displayContacts();
                break;
            case 3:
                std::cout << "Enter the name of the contact to search: ";
                std::cin >> name;
                manager.searchContact(name);
                break;
            case 4:
                std::cout << "Enter the name of the contact to update: ";
                std::cin >> name;
                manager.updateContact(name);
                saveContactsToFile(manager);
                break;
            case 5:
                std::cout << "Enter the name of the contact to delete: ";
                std::cin >> name;
                manager.deleteContact(name);
                saveContactsToFile(manager);
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
