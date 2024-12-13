#include "library.h"


int main(void)
{
	user *account = NULL;

	if (access(".profile_binary", R_OK) != 0)
		account = sign_up();
	else
		account = login();

	if (homepage(account->name) == 0)
	{
		exit(EXIT_SUCCESS);
	}

	free(account);
	return(0);
}
