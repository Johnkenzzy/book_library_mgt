#include "library.h"


int main(void)
{
	user *account = NULL;
	account = sign_up();

	homepage(&account->name);
	free(account);
	return(0);
}