#include <iostream>

#define	SIZE 8

typedef struct
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	darkest_secret;
	std::string	phone_number;
}	t_contact;

class	Phonebook
{
	private:
		int			filled;
		int			curIndex;
		t_contact	contacts[SIZE];
	public:
		Phonebook(int curIndex, int filled);
		void	ADD();
		void	fill_contact();
		void	SEARCH();
		void	display_raw(int index);
		void	ASK();
		void	display_info(int index);
};

void	dispaly_word(std::string str);
