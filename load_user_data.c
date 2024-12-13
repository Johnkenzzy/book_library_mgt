#include "library.h"


/**
 * load_user_binary - Loads data from binary file into current session
 * @filename: File name to load binary data from
 * Return: Nothing
 */
user *load_user_binary(const char *filename)
{
	FILE *file = fopen(filename, "rb");
	user *data_head = NULL, *data_tail = NULL, *new_data, temp;

	if (!file)
		return (NULL);

	while (fread(&temp, sizeof(user), 1, file) == 1)
	{
		new_data = malloc(sizeof(user));
		if (!new_data)
		{
			fclose(file);
			return (NULL);
		}

		*new_data = temp;
		new_data->next = NULL;

		if (!data_head)
		{
			data_head = new_data;
			data_tail = new_data;
		}
		else
		{
			data_tail->next = new_data;
			data_tail = new_data;
		}
	}

	fclose(file);
	return (data_head);
}
