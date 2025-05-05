#include <iostream>

int	main(int ac, char **av)
{
	int	myint = 0;

	myint = 10;
	myint = 20;
	myint = 10 + 20;

	myint += 10;
	myint -= 5 + myint;
	myint *= 10;
	myint /= 10;
	std::cout << myint << "\n";
	return (0);
}
