#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
	std::string prompt;
	PhoneBook phoneBook;

	int contactIndex = 0;
	int count = 0;
	while (true) {
		if (!(std::cin >> prompt)) {
			break;
		}
		if (prompt == "ADD") {
			if (contactIndex > 7) {
				contactIndex -= 8;
			}
			phoneBook.addContact(contactIndex);
			contactIndex++;
			if (++count > 8)
				count = 8;
		} else if (prompt == "SEARCH") {
			if (contactIndex == 0) {
				std::cout << "No contact saved." << std::endl;
				continue;
			}
			phoneBook.searchContact(count);
		} else if (prompt == "EXIT") {
			return 0;
		}
	}
	return 0;
}