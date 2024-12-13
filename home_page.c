#include "library.h"


/**
 * homepage - displays the home page with navigation options
 * @user: Pointer to the user's name
 * Return: Exit integer
 */
int homepage(char *user)
{
	int option, exit_stat = -1;
	const char *filename = ".library_binary";
	book *books_data = NULL;

	printf("\nWELCOME %s!\n", user);
	books_data = load_binary(filename);

	while(exit_stat != 0)
	{
		option = choose_option();
		exit_stat = option_action(option, &books_data, filename);
	}
	return (exit_stat);
}


/**
 * choose_option - Displays the prompt of options
 * Return: The option number
 */
int choose_option(void)
{
	int opt;

	printf("\n>>>>>> Library Home System <<<<<<\n");
	printf("\n... 1: To add a new book");
	printf("\n... 2: To view books");
	printf("\n... 3: To search book");
	printf("\n... 4: Save books to file");
	printf("\n... 5: To delete book");
	printf("\n... 0: To exit program");
	printf("\n>>> ");
	scanf("%d", &opt);
	getchar();

	return (opt);
}


/**
 * option_action - Initiates the option's action
 * @option: The option chosen
 * @books_data: Pointer to pointer to the books data
 * @file: The file stream to save books session data
 * Return: Exit integer
 */
int option_action(int option, book **books_data, const char *file)
{
	int exit = -1;

	if (option == 1)
		add_book(books_data);
	else if (option == 2)
		print_books(*books_data);
	else if (option == 3)
		handle_book_search(*books_data, "print");
	else if (option == 4)
	{
		item_num(*books_data);
		save_binary(file, *books_data);
	}
	else if (option == 5)
		handle_book_search(*books_data, "delete");
	else if (option == 0)
	{
		exit = 0;
		printf("Exiting...\n");
		free(*books_data);
		return(exit);
	}
	else
		printf("--> Invalid option, try again.\n");

	return (exit);
}
