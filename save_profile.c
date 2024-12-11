#include "library.h"


/**
 * sign_up - Handles new user sign up
 * Return: New user detail
 */
user *sign_up()
{
	user *new_user_detail;

	new_user_detail = malloc(sizeof(user));
	if (new_user_detail == NULL)
		return (NULL);

	printf("\n>>>>>>>>>>>>>>> Create an Account <<<<<<<<<<<<<<<\n\n");

	if ((input_get_display(new_user_detail)) == 0)
	{
		if (strcmp(new_user_detail->password, new_user_detail->confirm_pass) == 0)
		{
			printf("\n--> Account Creation Success!\n");
			save_user_binary(".profile_binary", new_user_detail);
			login();
		}
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
