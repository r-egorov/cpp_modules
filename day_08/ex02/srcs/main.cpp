#include "mutantstack.hpp"
#include <iostream>

int		main(void)
{
	{
		// Prepare a small stack and print it

		MutantStack<int>		original_stack;

		for (int i = 0; i < 10; i++)
		{
			original_stack.push(i);
		}

		print_mstack(original_stack, "Original stack");

		// Test copy constructor

		MutantStack<int>		copy_stack(original_stack);
		print_mstack(copy_stack, "Copy stack");

		for (MutantStack<int>::iterator	it = copy_stack.begin();
				it != copy_stack.end();
				it++)
		{
			*it *= 2;
		}

		print_mstack(copy_stack, "Copy stack after editing");
		print_mstack(original_stack, "Original stack after editing the copy");

		// Test assignment operator

		MutantStack<int>		assign_stack(original_stack);
		rprint_mstack(assign_stack, "Assign stack reverse");

		for (MutantStack<int>::iterator	it = assign_stack.begin();
				it != assign_stack.end();
				it++)
		{
			*it *= 2;
		}

		rprint_mstack(assign_stack, "Assign stack reverse after editing");
		rprint_mstack(original_stack, "Original stack reverse after editing the Assign");
	}
	{
		// Test MutantStack with strings
		

		MutantStack<std::string>	string_mstack;

		string_mstack.push("First!");
		string_mstack.push("Second!");
		string_mstack.push("Third!");
		string_mstack.push("Last!");

		rprint_mstack(string_mstack, "=String stack reverse=");
		std::cout << "String stack size = " << string_mstack.size() << std::endl;

		std::cout << "string_mstack.top() = " << string_mstack.top() << std::endl;

		string_mstack.pop();
		rprint_mstack(string_mstack, "=String stack reverse after one pop()=");
		std::cout << "String stack size = " << string_mstack.size() << std::endl;
	}
	return (0);
}
