#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

void    PhoneBook::print_phonebook(PhoneBook *phonebook)
{
    int i = 0;

    while (i < 8)
    {
        std::cout << "Contact " << i + 1 << std::endl;
        phonebook->list[i].print_contact(&phonebook->list[i]);
        i++;
    }
}

void    PhoneBook::add_contact_to_book(PhoneBook *phonebook, Contact *contact, int i)
{
    phonebook->list[i] = *contact;
}

int    PhoneBook::display_list(PhoneBook *phonebook)
{
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::setw(10) << "     Index|"
              << std::setw(10) << "First name|"
              << std::setw(10) << " Last name|"
              << std::setw(10) << "  Nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    int i = 0;
    while (i < 8)
    {
        if (phonebook->list[i].print_contact_list(i))
            break;
        i++;
    }
    std::cout << "--------------------------------------------" << std::endl;
    return (i);
}

void    PhoneBook::search_contact(PhoneBook *phonebook, int i)
{
    std::string index;
    std::cout << "Enter the index of the contact: ";
    std::getline(std::cin, index);
    if (index.length() > 1 || !std::isdigit(index[0]) || (index[0] - '0') >= i || i < 1)
    {
        std::cout << "The index is not correct." << std::endl;
        return;
    }
    i = index[0] - '0';
    phonebook->list[i].print_contact(&phonebook->list[i]);
    std::cout << "--------------------------------------------" << std::endl;
}
