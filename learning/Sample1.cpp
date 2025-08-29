#include <iostream>
#include "Sample1.hpp"

Sample1::Sample1(void) : foo(0)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample1::~Sample1(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample1::bar(void) const
{
	std::cout << "Member function bar called" << std::endl;
	return;
}