#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain {
    public:
        std::string ideas[100];
        Brain();
        Brain(const Brain &arg);
        ~Brain();
        Brain &operator=(const Brain &arg);
        std::string getIdea(int i) const;
        
 };

#endif