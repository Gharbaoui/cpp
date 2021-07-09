#include "awesome_phoneBook.hpp"

int	main(int argc, char **argv)
{
	std::string cmd;

	Phonebook phonebook(10);
	while (1)
	{
		std::cin >> cmd;
		if (cmd == "EXIT")
			return 0;
	//	else if (cmd == "ADD")
	}
}

Phonebook::Phonebook(int curIndex)
{
	this->curIndex = curIndex;
}
