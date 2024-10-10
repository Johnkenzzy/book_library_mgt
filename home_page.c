#include "main.h"


/**
 * homepage - displays the home page with navigation options
 * 
 * Return: nothing
 */
void homepage(char **user)
{
    book *books_database = NULL;
    int option = 0;

    printf("\nWELCOME! %s\n", *user);

   while(1)
   {
        printf("\n>>>>>> Library Home System <<<<<<\n");
        printf("\n... 1: To add a new book");
        printf("\n... 2: To view books");
        printf("\n... 0: To exit program");
        printf("\n>>> ");
        scanf("%d", &option);
        getchar();

        if (option == 1)
        {
            add_book(&books_database);
            continue;
        }
        else if (option == 2)
        {
            print_books(&books_database);
            continue;
        }
        else if (option == 0)
        {
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        }
        else
            printf("--> Invalid option, try again.\n");
   }
}