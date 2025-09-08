#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contact[8];

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(int i);
	void searchContact(int idx);
	void exit();
};

#endif