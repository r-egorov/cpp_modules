#include "Interface_class.hpp"

void	Interface::run(void)
{
	std::cout << FRESET(FGREEN("Welcome to `Awesome PhoneBook v1.0`")) << std::endl
		<< "Please, enter a command below." << std::endl;
	while ((std::cout << FRESET(FYELLOW("Enter a command: ")))
			&& (std::getline(std::cin, input)))
	{
		std::transform(
				input.begin(), input.end(), input.begin(), tolower);
		if (input == "exit")
			break ;
		else if (input == "add")
			this->add();
		else if (input == "search")
			this->search();
		else
			std::cout << FRESET(FRED("Invalid command. Try again.")) << std::endl;
	}
	this->stop();
}

void	Interface::stop(void)
{
	std::cout << "\nThank you for choosing `Awesome PhoneBook v1.0`" << std::endl
		<< "Bye-bye!" << std::endl;
}

void	Interface::add(void)
{
	Contact	contact;
	static std::string	print_iter[5] =
	{
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Darkest secret: ",
	};
	typedef void 		(Contact::*setter)(std::string);
	static setter 		methods_iter[5] =
	{
		&Contact::set_first_name,
		&Contact::set_last_name,
		&Contact::set_nickname,
		&Contact::set_phone_number,
		&Contact::set_darkest_secret,
	};

	std::cout
		<< FRESET(FYELLOW("Adding new contact! Please provide the necessary info."))
		<< std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << print_iter[i];
		std::getline(std::cin, this->input);
		(contact.*methods_iter[i])(input);
	}

	this->phonebook.add(contact);

	std::cout << FGREEN("Successfully added the contact \"")
		<< contact.get_first_name() << " " <<  contact.get_last_name() << FRESET("\"!")
		<< std::endl;
}

void	Interface::search(void)
{
	int	count = this->phonebook.get_count();

	if (count == 0)
	{
		std::cout
			<< FRESET(FRED("Phonebook is empty.")) 
			<< std::endl;
		return ;
	}

	if (count > 8)
		count = 8;

	std::cout
		<< "+----------------------------------+\n"
		<< "|           MY PHONEBOOK           |\n" 
		<< "+-+----------+----------+----------+"
		<< std::endl;

	for (int i = 0; i < count ; i++)
	{
		std::cout << "|" << i << "|";
		this->phonebook.search(i).entry_print();
	}
	std::cout << "+-+----------+----------+----------+" << std::endl;

	std::cout
		<< FRESET(FYELLOW("Enter the contact's index for the full information"))
		<< std::endl;

	int		flag;
	int		index;

	flag = 1;
	while (flag)
	{
		std::cout << FRESET(FYELLOW("Enter an index: "));
		std::cin >> index;

		if (std::cin.eof())
		{
			std::cerr << "ERROR unexpected EOF\n";
        	exit(1);
		}
		else if ((std::cin.fail())
			|| (index >= 8) || (index < 0)
			|| ((this->phonebook.get_count() < 8)
				&& (index > this->phonebook.get_count() - 1)))
		{
			std::cout
				<< FRESET(FRED("Invalid index. Try again."))
				<< std::endl;

		}
		else
		{
			std::cout
				<< "+----------------------------------+\n"
				<< "|           CONTACT CARD           |\n" 
				<< "+----------------------------------+"
				<< std::endl;
			this->phonebook.search(index).full_print();
			std::cout << "+----------------------------------+" << std::endl;
			flag = 0;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
