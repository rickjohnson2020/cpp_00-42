#include <iostream>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void PhoneBook::addContact(int i)
{
	Contact contact;
	PhoneBook phoneBook;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First Name: ";
	// TODO: error handling for empty?
	std::cin >> firstName;
	contact.setFirstName(firstName);
	std::cout << "Last Name: ";
	std::cin >> lastName;
	contact.setLastName(lastName);
	std::cout << "Nickname: ";
	std::cin >> nickname;
	contact.setNickName(nickname);
	std::cout << "Phone Number: ";
	std::cin >> phoneNumber;
	contact.setPhoneNumber(phoneNumber);
	std::cout << "Darkest Secret: ";
	std::cin >> darkestSecret;
	contact.setDarkestSecret(darkestSecret);

	this->contact[i] = contact;
	std::cout << "The contact has successfully been added." << std::endl;
}

void PhoneBook::searchContact()
{
	std::cout << "|Index     |" << "|First name|" << "|Last name |" << "|Nickname  |" << std::endl;
	for (int i = 0; i < sizeof(this->contact); i++)
	{
		std::string firstName = this->contact[i].getFirstName();
		std::cout << "|" << i << "         |";
		if (firstName.size() > 10)
		{
			firstName = firstName.substr(0, 8);
			firstName[10] = '.';
			std::cout << firstName << "|";
		}
		std::string lastName = this->contact[i].getLastName();
		if (lastName.size() > 10)
		{
			lastName = lastName.substr(0, 8);
			lastName[10] = '.';
			std::cout << firstName << "|";
		}
		std::string nickname = this->contact[i].getNickname();
		if (nickname.size() > 10)
		{
			nickname = nickname.substr(0, 8);
			nickname[10] = '.';
			std::cout << nickname << "|";
		}
	}
	int index;
	std::cout << "Index: ";
	std::cin >> index;
	if (index >= sizeof(this->contact) - 1 || index >= 0)
	{
		std::cout << "Wrong index." << std::endl;
		return;
	}
	std::cout << "First Name: " << this->contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contact[index].getDarkestSecret() << std::endl;
}