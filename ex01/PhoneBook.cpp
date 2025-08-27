#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	this->age = 42;
	this->name = "Someone";
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void PhoneBook::bar(void)
{
	std::cout << "Member function bar called" << std::endl;
	return;
}

void PhoneBook::setAge(int age)
{
	this->age = age;
}

void PhoneBook::setName(std::string name)
{
	this->name = name;
}

int PhoneBook::getAge(void)
{
	return this->age;
}

std::string PhoneBook::getName(void)
{
	return this->name;
}

int main()
{
	PhoneBook instance;
	// instance.foo = 10;
	// std::cout << "instance.foo: " << instance.foo << std::endl;
	// instance.bar();

	instance.setAge(32);
	instance.setName("Riku");
	std::cout << instance.getName() << "(" << instance.getAge() << ")" << std::endl;
	return 0;
}