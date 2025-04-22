#include "Bureaucrat.hpp"

int main()
{
	
	try
	{
		Bureaucrat Jule("Jule", 1);
		Bureaucrat Miriam("Miriam", 150);
		Jule.increase();
		std::cout << Jule;
		Miriam.decrease();
		std::cout << Miriam;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return(0);
}