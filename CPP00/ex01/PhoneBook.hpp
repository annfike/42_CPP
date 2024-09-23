#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact list[8];
  public:
      PhoneBook();
      ~PhoneBook();
      void print_phonebook(PhoneBook *phonebook);
      void add_contact_to_book(PhoneBook *phonebook, Contact *contact, int i);
      int display_list(PhoneBook *phonebook);
      void search_contact(PhoneBook *phonebook, int i);
};

#endif