#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook() {
	return;
}

PhoneBook::~PhoneBook() {
	return;
}

int setContact(Contact *contact, std::string output, std::string *input) {
	while (true) {
		std::cout << output;
		if (!(std::getline(std::cin, *input)))
			return 0;
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
		}
		break;
	}
	return 1;
}

void PhoneBook::addContact(int i) {
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cin.ignore();
	if (!(setContact(&contact, "First name: ", &firstName))) return;
	if (!(setContact(&contact, "Last name: ", &lastName))) return;
	if (!(setContact(&contact, "Nickname: ", &nickname))) return;
	if (!(setContact(&contact, "Phone number: ", &phoneNumber))) return;
	if (!(setContact(&contact, "Darkest secret: ", &darkestSecret))) return;

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
	int idx = -1;
	while (true) {
		std::string input;
		std::cout << "Index: ";
		if (!(std::cin >> input))
			return;
		if (!(input.size() == 1 && input[0] >= '0' && input[0] <= '7')) {
			std::cout << "Invalid input. Enter again." << std::endl;
			continue;
		}
		idx = input[0] - '0';
		if (idx > contactCount - 1 || idx < 0) {
			std::cout << "Invalid input. Enter again." << std::endl;
			continue;
		}
		break;
	}
	std::cout << "First name: " << this->contact[idx].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contact[idx].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact[idx].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contact[idx].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contact[idx].getDarkestSecret() << std::endl;
}