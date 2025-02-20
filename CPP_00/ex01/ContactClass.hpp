#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();
		void	AddNewContact();
		void	DisplayAllContacts(int ContactIndex);
		void	DisplayOneContact();
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
		void	AddContactField(std::string prompt, std::string &field, int entry);
		bool	IsAlphabetical(std::string Name);
		bool	IsNumerical(std::string PhoneNumber);
};
#endif