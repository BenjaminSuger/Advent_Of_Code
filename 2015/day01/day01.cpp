#include <iostream>
#include <fstream>

int	main(void)
{
	long		floor = 0;
	bool		on = true;
	size_t		steps = 1;
	std::string	input;
	std::ifstream	file("input.txt", std::ifstream::in);
	std::getline(file, input);

	for (auto it : input)
	{
		if (it == '(')
			floor++;
		else if (it == ')')
			floor--;
		if (on && floor == -1)
		{
			on = false;
			std::cout << "The elevator brings you to -1 level after " << steps << " steps\n";
		}
		steps++;
	}
	std::cout << "You are at floor : " << floor << "\n";
}
