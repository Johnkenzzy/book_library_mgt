#include "library.h"


int main(void)
{
	user *account = NULL;

	if (access(".profile_binary", R_OK) != 0)
		account = sign_up();
	else
		account = login();

	homepage(account->name);
	free(account);
	return(0);
}
