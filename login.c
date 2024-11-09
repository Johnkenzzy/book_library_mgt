#include "library.h"


/**
 * sign_up - handles new users sign up
 *
 * @new_user_detail: registration details of a new user
 *
 * Return: new_user_detail
 */
user *sign_up(void)
{
	user *new_user_detail;

	new_user_detail = malloc(sizeof(user));
	if (new_user_detail == NULL)
		return (NULL);

	printf("\n>>>>>>>>>>>>>>> Create an Account <<<<<<<<<<<<<<<\n\n");

	if ((input_get_display(new_user_detail)) == 0)
	{
		if (strcmp(new_user_detail->password, new_user_detail->confirm_pass) == 0)
			printf("\n--> Login Success!\n");
		else
		{
			printf("--> Passwords doesn't match\n");
			free(new_user_detail);
			sign_up();
		}
	}
	else
	{
		free(new_user_detail);
		sign_up();
	}

	return (new_user_detail);
}


/**
 * get_input - reads user input from the keyboard
 *
 * @input: pointer to the struct containing the user's detail
 *
 * Return: 0 if successful, else 1
 */
size_t get_input(char **input)
{
	size_t chars_read = 0;
	size_t read_size;

	*input = NULL;
	read_size = getline(&(*input), &chars_read, stdin);
	if (read_size < 1)
	{
		free(input);
		return (0);
	}
	return (read_size - 1);
}



/**
 * get_input_display - displays get input prompts
 *
 * @new_user_detail: registration details of a new user
 *
 * Return: 0 if successful, else 1
 */
int input_get_display(user *new_user_detail)
{
	size_t name_len = 0;
	size_t pass_len = 0;
	
	printf(">>> New Username: ");
	name_len = get_input(&(new_user_detail->name));
	if (name_len < 2 || name_len > 20)
	{
		printf("--> Too short or too long username: %s", new_user_detail->name);
		printf("--> Enter a name between 2 and 20 characters\n");
		free(new_user_detail->name);
		return (1);
	}

	printf(">>> New Password: ");
	pass_len = get_input(&(new_user_detail->password));
	if (pass_len < 4 || pass_len > 8)
	{
		printf("--> Make sure to create a password between 4 and 8 characters\n");
		free(new_user_detail->name);
		free(new_user_detail->password);
		return (1);
	}
	printf(">>> Confirm Password: ");
	get_input(&(new_user_detail->confirm_pass));
	
	return (0);
}