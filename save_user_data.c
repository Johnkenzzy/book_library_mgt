#include "library.h"


/**
 * save_user_binary - Saves data of current session to binary file
 * @filename: File name to save binary data to
 * @data: Data to be saved
 * Return: Nothing
 */
void save_user_binary(const char *filename, user *data_head)
{
	FILE *file = fopen(filename, "wb");
	user *curr_user;

	if (!file)
		return;

	curr_user = data_head;
	while (curr_user)
	{
		fwrite(curr_user, sizeof(user), 1, file);
		curr_user = curr_user->next;
	}

	fclose(file);
}
