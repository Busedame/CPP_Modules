#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP
#include <iostream>
#include <cctype>
#include <cstring>
#include <limits>
#include <cstdlib>
#include "ContactClass.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	AddContactToPhoneBook(void);
		void	DisplayContacts(void);
	private:
		int		PromptForOneContact(void);
		void	DisplayContactHeader(void);
		Contact Contacts[8];
		int		NoContact;
		int		TotContacts;
};
#endif