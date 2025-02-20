#include "PhoneBookClass.hpp"

PhoneBook::PhoneBook() : NoContact(0), TotContacts(0){}
PhoneBook::~PhoneBook(){}

void	PhoneBook::AddContactToPhoneBook(void)
{
	if (TotContacts == 8)
	{
		if (NoContact == 8)
			NoContact = 0;
		Contacts[NoContact].AddNewContact();
		NoContact++;
	}
	else
	{
		Contacts[NoContact].AddNewContact();
		NoContact++;
		TotContacts++;
		if (TotContacts == 8)
			NoContact = 0;
	}
}

void	PhoneBook::DisplayContactHeader(void)
{
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << \
	"First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) \
	<< "Nickname" << "|" << std::endl;
}

int	PhoneBook::PromptForOneContact(void)
{
	long		InputIndex;
	std::string	Input;
	char		*EndPtr;

	std::cout << std::endl; std::cout << "Want to know more about each contact?" << std::endl;
	std::cout << "Enter the index of the contact you want to see. Index must be between 0 and 7." << std::endl;
	while (1)
	{
		std::cout << "Index: "; std::cin >> Input;
		InputIndex = std::strtol(Input.c_str(), &EndPtr, 10);
		if (*EndPtr != '\0' || InputIndex < 0 || InputIndex > 7)
			std::cout << "Index must be numerical, and between 0 and 7." << std::endl;
		else if (InputIndex > TotContacts - 1)
			std::cout << "Contact doesnt't exist. Please enter another index." << std::endl;
		if (*EndPtr == '\0' && InputIndex >= 0 && InputIndex <= 7 && InputIndex <= TotContacts - 1)
			break ;
	}
	std::cout << std::endl;
	return (InputIndex);
}

void	PhoneBook::DisplayContacts(void)
{
	if (TotContacts == 0)
	{
		std::cout << "No contacts to display, please add a contact." << std::endl;
		return ;
	}
	DisplayContactHeader();
	for (int ContactIndex = 0; ContactIndex < TotContacts; ContactIndex++)
		Contacts[ContactIndex].DisplayAllContacts(ContactIndex);
	Contacts[PromptForOneContact()].DisplayOneContact();
}
