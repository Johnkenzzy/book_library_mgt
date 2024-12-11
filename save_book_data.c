#include "library.h"


/**
 * save_binary - Saves data of current session to binary file
 * @filename: File name to save binary data to
 * @data: Data to be saved
 * Return: Nothing
 */
void save_binary(const char *filename, book *data_head)
{
	FILE *file = fopen(filename, "wb");
	book *curr_book, *reload;

	if (!file)
		return;

	curr_book = data_head;
	while (curr_book)
	{
		fwrite(curr_book, sizeof(book), 1, file);
		curr_book = curr_book->next;
	}

	reload = load_binary(filename);
	print_books(reload);

	fclose(file);
}