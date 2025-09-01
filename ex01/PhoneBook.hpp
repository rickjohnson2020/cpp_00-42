#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(int i);
	void searchContact();
	void exit();
};

#endif