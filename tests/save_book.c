#include "../library.h"

/**
 * main - Entry point
 *
 * Return: 0 (Always successful)
 */
int main(void)
{
	const char *text = "Johnkennedy Is A Good Engineer\n";
	char *reload = malloc(sizeof(char));
	size_t n = strlen(text);
	
	printf("%s", text);
	save_binary("text.b", text, n);
	load_binary("text.b", reload, n);
	printf("%s", reload);

	free(reload);
	return (0);
}
