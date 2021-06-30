#include <iostream>
#include <fstream>

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage:\n./replace filename source_string target_string" << std::endl;
		return (1);
	}

	std::string		file_name = argv[1];
	std::string		source_string = argv[2];
	std::string		target_string = argv[3];

	if (file_name.empty() || source_string.empty() || target_string.empty())
	{
		std::cerr << "Error: arguments must not be empty" << std::endl;
		return (2);
	}

	std::ifstream	input_file;

	input_file.open(file_name);
	if (!input_file.is_open())
	{
		std::cerr << "Error when opening the source file" << std::endl;
		return (2);
	}

	std::ofstream	output_file;

	output_file.open(file_name + ".REPLACE", std::ios::trunc);
	if (!input_file.is_open())
	{
		std::cerr << "Error when creating the output file" << std::endl;
		return (3);
	}

	std::string		line;
	int				matches = 0;

	while(std::getline(input_file, line))
	{
		std::size_t		found = 0;
		std::cout << line << std::endl;
		while (found != std::string::npos)
		{
			found = line.find(source_string, found);

			if (found != std::string::npos)
			{
				matches += 1;
				line.erase(found, source_string.length());
				//std::cout << "AFTER ERASING: " << line << std::endl;
				line.insert(found, target_string);
				//std::cout << "AFTER INSERTING: " << line << std::endl;
				//std::cout << found << std::endl;
				found += source_string.length();
			}
		}
		output_file << line << std::endl;
	}
	input_file.close();
	output_file.close();

	return (0);
}
