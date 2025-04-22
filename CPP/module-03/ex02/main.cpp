#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ScavTrap pino;
    ScavTrap luca("Luca");
    ScavTrap gianni("Gianni");
    FragTrap sara("Sara");

    pino = gianni;  //pino adesso e' gianni LMAO (elem ayyooo)
    std::cout << std::endl;

    // Test attacks
    luca.attack("Gianni");
    gianni.takeDamage(5);
    gianni.beRepaired(3);
    std::cout << std::endl;

    // Test high fives
    sara.highFivesGuys();
    std::cout << std::endl;

    // Test more interactions
    sara.attack("Luca");
    luca.takeDamage(10);
    luca.beRepaired(5);
    std::cout << std::endl;

    return (0);
}