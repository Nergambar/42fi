#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <iostream>


class Command
{
    private:
        std::string name;
        size_t type;
    public:
       Command();
       Command(const Command &src);
       Command &operator=(const Command &src);
       ~Command();
       int     getCommand(std::string name);
};

#endif