#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	for (int i = 5; i > 0; i--)
	{
		std::cout << i << "\t";
		std::cout << "Generate: " << 6 - i << std::endl;
		Base *base = generate();
		std::cout << "from pointer: " << 6 - i << std::endl;
		identify(base);
		std::cout << "from reference: " << 6 - i << std::endl;
		identify(*base);
		delete(base);
	}
	return (69);
}