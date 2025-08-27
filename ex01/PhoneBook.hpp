#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class PhoneBook
{
private:
	int age;
	std::string name;

public:
	PhoneBook(void);
	~PhoneBook(void);

	int foo;
	void bar(void);
	void setAge(int age);
	void setName(std::string name);
	int getAge(void);
	std::string getName(void);
};

#endif