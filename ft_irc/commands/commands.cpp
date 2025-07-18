#include "commands.hpp"

Command::Command()
{
    std::cout << "Default constructor called" << std::endl;
}

Command::~Command()
{
    std::cout << "Default destructor called" << std::endl;
}

Command::Command(const Command &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Command     &Command::operator = (const Command &src)
{
    return (*this);
}

int Command::getCommand(std::string name)
{
    size_t which;

    if (name == "KICK")
        return(1);
    else if (name == "INVITE")
        return(2);
    else if (name == "TOPIC")
        return(3);
    else if (name == "MODE")
        return(4);
    else
        return(999);
}