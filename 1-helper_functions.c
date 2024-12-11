#include "library.h"

size_t item_num(book *data)
{
	book *temp;
	size_t n = 0;

	temp = data;
	while (temp)
	{
		n++;
		temp = temp->next;
	}

	return (n);
}
