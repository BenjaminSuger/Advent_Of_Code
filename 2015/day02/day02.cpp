#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <array>

int	calculation(std::array<int, 3>	tab, size_t *ribbon)
{
	int	result;

	result = (2 * (tab[0] * tab[1])) + (2 * (tab[1] * tab[2])) + (2 * (tab[0] * tab[2]));
	std::sort(tab.begin(), tab.end());
	result += (tab[0] * tab[1]);
	
	*ribbon += (tab[0] * 2) + (tab[1] * 2);
	*ribbon += tab[0] * tab[1] * tab[2];
	return (result);
}

int	main(int argc, char **argv)
{
	//setup
	if (argc != 2)
		return (1);
	std::ifstream	file(argv[1], std::ifstream::in);

	std::array<int, 3>	tab{0, 0, 0};
	std::string		line;
	size_t			length = 0;
	size_t			l_ribbon = 0;

	while (std::getline(file, line))
	{
		tab[0] = std::atoi(std::strtok((char *)line.c_str(), "x"));
		tab[1] = std::atoi(std::strtok(NULL, "x"));
		tab[2] = std::atoi(std::strtok(NULL, "x"));
		length += calculation(tab, &l_ribbon);
	}
	std::cout << "length = " << length << "\n";
	std::cout << "ribbon = " << l_ribbon << "\n";
}
