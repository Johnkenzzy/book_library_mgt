#include "library.h"


/**
 * login - Handles user login
 * Return: Pointer to user detail
 */
user *login()
{
	user *user_detail, *profile_reload = NULL;
	const char *filename = ".profile_binary";

	user_detail = malloc(sizeof(user));
	if (user_detail == NULL)
		return (NULL);

	printf("\n>>>>>>>>>>>>>>>  Login to Profile <<<<<<<<<<<<<<<\n\n");

	if ((input_get_display(user_detail)) == 0)
	{
		if (access(filename, R_OK) == 0)
		{
			profile_reload = load_user_binary(filename);
			if ((strcmp(user_detail->name,
				profile_reload->name) == 0) &&
					(strcmp(user_detail->password,
						profile_reload->password) == 0))
			{
				printf("\n--> Login Success!\n");
			}
			else
			{
				printf("--> Login Failure, Try Again\n");
				login();
			}
		}
		else
		{
			printf("--> Account does not exit, create one\n");
			free(user_detail);
			sign_up();
		}
	}
	else
	{
		free(user_detail);
		login();
	}

	return (user_detail);
}


/**
 * get_input - reads user input from the keyboard
 * @input: pointer to the struct containing the user's detail
 * Return: Number of characters read
 */
size_t get_input(char *input)
{
	size_t chars_read = 0;
	
	fgets(input, MAX_INPUT, stdin);
	chars_read = strlen(input);
	
	return (chars_read);
}



/**
 * get_input_display - displays get input prompts
 * @user_detail: registration details of a user
 * Return: 0 if successful, else 1
 */
int input_get_display(user *user_detail)
{
	size_t name_len = 0;
	size_t pass_len = 0;
	
	printf(">>> Username: ");
	name_len = get_input(user_detail->name);
	user_detail->name[strcspn(user_detail->name, "\n")] = '\0';
	if (name_len < 2 || name_len > 20)
	{
		printf("--> Too short or too long username: ");
		printf("%s", user_detail->name);
		printf("--> Enter a name between 2 and 20 characters\n");
		return (1);
	}

	printf(">>> Password: ");
	pass_len = get_input(user_detail->password);
	user_detail->password[strcspn(user_detail->password, "\n")] = '\0';
	if (pass_len < 4 || pass_len > 11)
	{
		printf("--> Make sure password between is 4 and 10 characters\n");
		return (1);
	}
	printf(">>> Confirm Password: ");
	get_input(user_detail->confirm_pass);
	user_detail->confirm_pass[strcspn(user_detail->confirm_pass, "\n")] = '\0';
	
	return (0);
}
