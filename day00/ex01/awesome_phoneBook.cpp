#include "awesome_phoneBook.hpp"

int	main(int argc, char **argv)
{
	std::string cmd;

	Phonebook phonebook(0, 0);
	while (1)
	{
		std::cout << "command: ";
		std::cin >> cmd;
		if (cmd == "EXIT")
			return 0;
		else if (cmd == "ADD")
			phonebook.ADD();
		else if (cmd == "SEARCH")
			phonebook.SEARCH();
	}
}

/// ADD
Phonebook::Phonebook(int curIndex, int filled)
{
	this->curIndex = curIndex;
	this->filled = filled;
}

void	Phonebook::ADD()
{
	fill_contact();
	curIndex++;
	filled++;
	if (filled > 8)
		filled = 8;
	if (curIndex > 7)
		curIndex = 0;
}

void	Phonebook::fill_contact()
{
	std::cout << "first name: ";
	std::cin >> contacts[curIndex].first_name;
	std::cout << "last name: ";
	std::cin >> contacts[curIndex].last_name;
	std::cout << "nick name: ";
	std::cin >> contacts[curIndex].nick_name;
	std::cout << "darkest secret: ";
	std::cin >> contacts[curIndex].darkest_secret;
	std::cout << "phone number: ";
	std::cin >> contacts[curIndex].phone_number;
}

/// seach //

void	Phonebook::SEARCH()
{
	int	i;

	i = -1;
	if (filled)
		std::cout << "|  Index   |First Name| Last Name| Nick Name|\n";
	else
	{
		std::cout << "empty phone book\n";
		return ;
	}
	while (++i < filled)
		display_raw(i);
	ASK();
}

void	Phonebook::display_raw(int index)
{
	std::cout << "|    " << index << "     ";
	dispaly_word(contacts[index].first_name);
	dispaly_word(contacts[index].last_name);
	dispaly_word(contacts[index].nick_name);
	std::cout << "|\n";
}

void	Phonebook::ASK()
{
	int	index;

	std::cout << "Enter the index of a contact: ";
	std::cin >> index;
	if (index <= filled - 1)
		display_info(index);
	else
		std::cout << "Not Valid Index\n";
}

void	Phonebook::display_info(int index)
{
	std::cout << contacts[index].first_name << "\n";
	std::cout << contacts[index].last_name << "\n";
	std::cout << contacts[index].nick_name << "\n";
	std::cout << contacts[index].darkest_secret << "\n";
	std::cout << contacts[index].phone_number << "\n";
}

void	dispaly_word(std::string str)
{
	int i;

	i = -1;
	std::cout << "|";
	while (str[++i] && i < 9)
		std::cout << str[i];
	if (str[i] && i == 9)
		std::cout << ".";
	else
	{
		i--;
		while (++i < 10)
			std:: cout << " ";
	}
}
