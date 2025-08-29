#include <iostream>
#include "Sample1.hpp"

int main()
{
	Sample1 instance;
	Sample1 *instancep = &instance;

	int Sample1::*p = NULL;
	void (Sample1::*f)(void) const;

	p = &Sample1::foo;

	std::cout << "Value of member foo: " << instance.foo << std::endl; // 0
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl; // 21
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl; // 42

	f = &Sample1::bar;

	(instance.*f)();
	(instancep->*f)();

	return 0;
}
