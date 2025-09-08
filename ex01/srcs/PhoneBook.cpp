#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook(void) {
	std::cout << "Constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void setContact(Contact *contact, std::string output, std::string *input) {
	while (true) {
		std::cout << output;
		std::getline(std::cin, *input);
		if (*input == "") {
			std::cout << "This field can't be empty. Enter again." << std::endl;
			continue;
		} else {
			if (output == "First name: ") {
				contact->setFirstName(*input);
			} else if (output == "Last name: ") {
				contact->setLastName(*input);
			} else if (output == "Nickname: ") {
				contact->setNickname(*input);
			} else if (output == "Phone number: ") {
				contact->setPhoneNumber(*input);
			} else if (output == "Darkest secret: ") {
				contact->setDarkestSecret(*input);
			}
			return;
		}
	}
}

void PhoneBook::addContact(int i) {
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cin.ignore();
	setContact(&contact, "First name: ", &firstName);
	setContact(&contact, "Last name: ", &lastName);
	setContact(&contact, "Nickname: ", &nickname);
	setContact(&contact, "Phone number: ", &phoneNumber);
	setContact(&contact, "Darkest secret: ", &darkestSecret);

	this->contact[i] = contact;
	std::cout << "The contact has successfully been added." << std::endl;
}

void printColumn(const std::string &str) {
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << str;
}

void PhoneBook::searchContact(int contactCount) {
	std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
	for (int i = 0; i < contactCount; i++) {
		std::cout << "|" << std::setw(10) << i << "|";
		printColumn(this->contact[i].getFirstName());
		std::cout << "|";
		printColumn(this->contact[i].getLastName());
		std::cout << "|";
		printColumn(this->contact[i].getNickname());
		std::cout << "|" << std::endl;
	}
	int index;
	std::cout << "Index: ";
	std::cin >> index;
	if (index > contactCount - 1 || index < 0) {
		std::cout << "Wrong index." << std::endl;
		return;
	}
	std::cout << "First name: " << this->contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contact[index].getDarkestSecret() << std::endl;
}