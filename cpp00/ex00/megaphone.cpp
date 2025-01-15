#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			for(int j = 0; av[i][j]; j++)
				av[i][j] = (char)toupper(av[i][j]);
			std::cout << av[i];
			if (av[i])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << std::endl;}
}