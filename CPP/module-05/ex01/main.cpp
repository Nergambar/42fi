#include "Bureaucrat.hpp"

int main()
{
    try
	{
    	Bureaucrat *paolo = new Bureaucrat("Paolo", 4);
    	Bureaucrat *giuseppe = new Bureaucrat("Giuseppe", 2);  
		Form *c14 = new Form("c14", 20, 20);
        // paolo->decrementGrade();
		//     std::cout << *paolo;
        // giuseppe->incrementGrade();
        //     std::cout << *giuseppe;
		// paolo->decrease();
		//     std::cout << *paolo;
		// giuseppe->increase();
		//     std::cout << "\n\n\n\n" << *giuseppe;
		// paolo->signForm(*c14);
		giuseppe->signForm(*c14);
		giuseppe->signForm(*c14);
		delete paolo;
		delete giuseppe;
		delete c14;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    return (0);
}
