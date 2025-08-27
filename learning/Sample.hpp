#ifndef SAMPLE_HPP
#define SAMPLE_HPP

#include <iostream>

class Sample
{
private:
	char a1;
	int a2;
	float a3;

public:
	Sample(char p1, int p2, float p3);
	~Sample();
};

Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{
	std::cout << "Constructor called" << std::endl;
	// this->a1 = p1;
	std::cout << "this->a1 = " << this->a1 << std::endl;

	// this->a2 = p2;
	std::cout << "this->a2 = " << this->a2 << std::endl;

	// this->a3 = p3;
	std::cout << "this->a3 = " << this->a3 << std::endl;
	return;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

#endif