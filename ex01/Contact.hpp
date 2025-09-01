#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();
	~Contact();

	void setFirstName(std::string _firstName);
	void setLastName(std::string _lastName);
	void setNickName(std::string _nickname);
	void setPhoneNumber(std::string _phoneNumber);
	void setDarkestSecret(std::string _darkestSecret);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
};

#endif
