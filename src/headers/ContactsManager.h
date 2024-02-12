#ifndef CONTACTSMANAGER_H
#define CONTACTSMANAGER_H

#include <vector>
#include "Contact.h"

class ContactsManager {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact);
    void displayContacts() const;
    void searchContact(const std::string& name) const;
    void updateContact(const std::string& name);
    void deleteContact(const std::string& name);

    const std::vector<Contact>& getContacts() const {
        return contacts;
    }
};

#endif
