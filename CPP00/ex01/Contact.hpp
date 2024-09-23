#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
    public:
        Contact();
        ~Contact();
        void print_contact(Contact *contact);
        void add_contact(Contact *contact);
        int print_contact_list(int i);
};

#endif