#include "Contact.hpp"

Contact::Contact()
{
    /*this->first_name = "a";
    this->last_name = "b";
    this->nickname = "c";
    this->phone_number = "1";
    this->secret = "2";*/
}

Contact::~Contact()
{}

void    Contact::print_contact(Contact *contact)
{
    std::cout << "First name: " << contact->first_name << std::endl;
    std::cout << "Last name: " << contact->last_name << std::endl;
    std::cout << "Nickname: " << contact->nickname << std::endl;
    std::cout << "Phone number: " << contact->phone_number << std::endl;
    std::cout << "Darkest secret: " << contact->secret << std::endl;
}

int    Contact::print_contact_list(int i)
{
    if (first_name.empty())
        return (1);
    std::cout << std::right << std::setw(10) << i << "|";
	if (first_name.size() > 10)
		std::cout << std::right << std::setw(9) << first_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << first_name.substr(0, 10) << "|";
	if (last_name.size() > 10)
		std::cout << std::right << std::setw(9) << last_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << last_name.substr(0, 10) << "|";
	if (nickname.size() > 10)
		std::cout << std::right << std::setw(9) << nickname.substr(0, 9) << "." << "|" << std::endl;
	else
		std::cout << std::right << std::setw(10) << nickname.substr(0, 10) <<"|" << std::endl;
    return (0);
}

static bool spaceinput(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
            return (false);
    }
    return (true);
}

static std::string    check_input(std::string input, std::string message)
{
    while (!isprint(input[0]) || input.empty() || spaceinput(input)) {
        if (std::cin.eof()) 
        {
            std::cout << std::endl;
            exit(0);
        }
        std::cout << "Your input is not correct. " << std::endl;
        std::cout << message;
        std::getline(std::cin, input);
    }
    return (input);
}


void    Contact::add_contact(Contact *contact)
{
    std::string input;
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contact->first_name = check_input(input, "Enter first name: ");
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact->last_name = check_input(input, "Enter last name: ");
    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact->nickname = check_input(input, "Enter nickname: ");
    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact->phone_number = check_input(input, "Enter phone number: ");
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contact->secret = check_input(input, "Enter darkest secret: ");
}
