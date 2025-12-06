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

	int *ptr_x, *ptr_y;
	int x = 0, y = 0, x_robot = 0, y_robot = 0;
	std::set<std::pair<int, int>> houses;
	houses.insert(std::pair<int, int>{x, y});

	for (int i = 0; line[i]; i++)
	{
		if (i % 2 == 0)
			(ptr_x = &x, ptr_y = &y);
		else
			(ptr_x = &x_robot, ptr_y = &y_robot);
		switch (line[i])
		{
			case '^':
				(*ptr_y)++;
				break;
			case 'v':
				(*ptr_y)--;
				break;
			case '>':
				(*ptr_x)++;
				break;
			case '<':
				(*ptr_x)--;
				break;
		}
		houses.insert(std::pair<int, int>{*ptr_x, *ptr_y});
	}
	std::cout << "result = " << houses.size() << "\n";
	return (0);
}
