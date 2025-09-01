#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	std::string prompt;
	PhoneBook phoneBook;

	int contactIndex = 0;
	while (true)
	{
		std::cin >> prompt;
		if (prompt == "ADD")
		{
			phoneBook.addContact(contactIndex);
			contactIndex++;
		}
		else if (prompt == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (prompt == "EXIT")
		{
			return 0;
		}
	}
}