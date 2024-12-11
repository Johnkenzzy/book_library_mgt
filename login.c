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
		printf("Enters1\n");
		if (access(filename, R_OK) == 0)
		{
			printf("Enters2\n");
			profile_reload = load_user_binary(filename);
			printf("Enters3\n");
			printf("%s\n", profile_reload->name);
			/* Problem site: Solution -> Allocate a fixed memory for user data */
			if ((strcmp(user_detail->name,
				profile_reload->name) == 0) &&
					(strcmp(user_detail->password,
						profile_reload->password) == 0))
			{
				printf("Enters4\n");
				printf("\n--> Login Success!\n");
			}
			else
			{
				printf("Enters5\n");
				printf("--> Login Failure, Try Again\n");
				free(user_detail);
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
 * @user_detail: registration details of a user
 * Return: 0 if successful, else 1
 */
int input_get_display(user *user_detail)
{
	size_t name_len = 0;
	size_t pass_len = 0;
	
	printf(">>> Username: ");
	name_len = get_input(&(user_detail->name));
	user_detail->name[strcspn(user_detail->name, "\n")] = '\0';
	if (name_len < 2 || name_len > 20)
	{
		printf("--> Too short or too long username: ");
		printf("%s", user_detail->name);
		printf("--> Enter a name between 2 and 20 characters\n");
		free(user_detail->name);
		return (1);
	}

	printf(">>> Password: ");
	pass_len = get_input(&(user_detail->password));
	user_detail->password[strcspn(user_detail->password, "\n")] = '\0';
	if (pass_len < 4 || pass_len > 8)
	{
		printf("--> Make sure password between is 4 and 8 characters\n");
		free(user_detail->name);
		free(user_detail->password);
		return (1);
	}
	printf(">>> Confirm Password: ");
	get_input(&(user_detail->confirm_pass));
	user_detail->confirm_pass[strcspn(user_detail->confirm_pass, "\n")] = '\0';
	
	return (0);
}
