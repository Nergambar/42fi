#include "HumanA.hpp"
#include "HumanB.hpp"

/*int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA marco("Marco", club);
		marco.attack();
		club.setType("some other type of club");
		marco.attack();
	}
	{
		Weapon club = Weapon(NULL);
		HumanB sergio("Sergio");
		sergio.setWeapon(club);
		sergio.attack();
		club.setType("crude spiked club");
		sergio.attack();
	}
}*/

int main()
{
    { // Objects created within a scope are automatically destroyed when the scope ends
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
    {
        HumanB tom("Tom");
        tom.attack(); // Tom has no weapon
        Weapon club = Weapon("crude spiked club");
        tom.setWeapon(club);
        tom.attack();
        club.setType("some other type of club");
        tom.attack();
    }
    return 0;
}