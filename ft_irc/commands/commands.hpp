#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <iostream>


class Command
{
    private:
        size_t type;
    public:
       Command();
       Command(const Command &src);
       Command &operator=(const Command &src);
       ~Command();
};

#endif