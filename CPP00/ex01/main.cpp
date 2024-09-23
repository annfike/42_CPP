#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
    int i = 0;
    int count = 0;
    
    while(1)
    {
        std::string command;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin,command);
        if (std::cin.eof()) 
        {
            std::cout << std::endl;
            break;
        }
        if (command == "EXIT")
            break;
        else if (command == "ADD")
        {
            Contact contact;
            if (i == 8)
                i = 0;
            contact.add_contact(&contact);
            phonebook.add_contact_to_book(&phonebook, &contact, i);
            i++;
            //phonebook.print_phonebook(&phonebook);
        }
        else if (command == "SEARCH")
        {
            count = phonebook.display_list(&phonebook);
            phonebook.search_contact(&phonebook, count);
        }
    }
	return (0);
}
