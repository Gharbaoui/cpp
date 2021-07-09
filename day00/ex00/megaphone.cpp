#include <iostream>

void	cap_str(char *str)
{
	while (*str)
	{
		std::cout << (char)toupper(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (++i < argc)
		{
			cap_str(argv[i]);
			if (i + 1 < argc)
				std::cout << " ";
		}
	}
	std::cout << "\n";
}
