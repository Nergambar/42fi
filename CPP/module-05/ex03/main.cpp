#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *form;

    // Test valid form creation
    std::cout << "=== Valid Form Creation ===" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Target1");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Target2");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Target3");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    // Test invalid form creation
    std::cout << "=== Invalid Form Creation ===" << std::endl;
    form = someRandomIntern.makeForm("unknown form", "Target4");
    if (!form)
    {
        std::cout << "Failed to create form: unknown form" << std::endl;
    }

    return 0;
}