#include <iostream>
#include <set>
#include <utility>
#include <fstream>

int	main(int argc, char **argv)
{
	////////////////////////////////////////////////////////
	if (argc != 2)
	{
		std::cout << "Usage ; ./a.out <input files>\n";
		return (1);
	}
	std::ifstream	file(argv[1], std::ifstream::in);
	std::string	line;
	std::getline(file, line);
	//////////////////////////////////////////////////////
	
	int x, y = 0;
	std::set<std::pair<int, int>> houses;
	houses.insert(std::pair<int, int>{x, y});

	for (auto it : line)
	{
		switch (it)
		{
			case '^':
				y++;
				break;
			case 'v':
				y--;
				break;
			case '>':
				x++;
				break;
			case '<':
				x--;
				break;
		}
		houses.insert(std::pair<int, int>{x, y});
	}
	std::cout << "result = " << houses.size() << "\n";
	return (0);
}
