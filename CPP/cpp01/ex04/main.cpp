#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "not quite the required args" << std::endl;
		return (1);
	}
	std::string		str;
	std::string		buf;
	std::string		replace;
	std::ifstream	IFd; //input file stream
	std::ofstream	OFd; //output file stream (per scrivere sui file)
	std::string		output;
	size_t			pos = std::string::npos;

	replace = av[2];
	IFd.open(av[1]);
	if (!IFd.is_open())
	{
		std::cout << "HaHa, very funny.\nwrong file inserted" << std::endl;
		return (1);
	}
	output = av[1];
	output += ".replace";
	OFd.open(output.c_str());
	if (!OFd.is_open())
	{
		std::cout << "something has gone terribly wrong" << std::endl << "the wizard must be stopped" << std::endl;
		IFd.close();
		return (1);
	}
	while(getline(IFd, buf))
	{
		buf += "\n";
		str += buf;
	}
	IFd.close();
	str = str.substr(0, str.length() - 1);
	do
    {
        pos = str.find(replace);
        if (pos == 0)
            OFd << av[3];
        OFd << str.substr(0, pos);
        if (pos > 0 && pos != std::string::npos)
            OFd << av[3];
        if ((long long int)str.length() - (long long int)replace.length() > 0 )
            str = str.substr(pos + replace.length(), str.length());
    } while (pos != std::string::npos);
	OFd.close();
	std::cout << "replacement failed successfully!" << std::endl;
	return (0);
}