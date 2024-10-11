#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        if (i < 10)
        {
            std::stringstream ss;
            ss << "Idea " << i; // Записываем строку в stringstream
            std::string idea = ss.str(); // Получаем строку из stringstream
            ideas[i] = idea;
        }
        else
            ideas[i] = "I have no idea";
    }
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &arg)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = arg;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &arg)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &arg)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = arg.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int i) const
{
    return ideas[i];
}

