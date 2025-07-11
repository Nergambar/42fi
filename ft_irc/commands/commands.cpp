#include "commands.hpp"

Command::Command()
{
    std::cout
}

Command::~Command(){}

Command::Command(const Command &src)
{
    *this = src;
}