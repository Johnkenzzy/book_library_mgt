#include "library.h"


/**
 * homepage - displays the home page with navigation options
 * 
 * Return: nothing
 */
void homepage(char **user)
{
    book *books_database = NULL;
    int option = 0;

    printf("\nWELCOME %s", *user);

   while(1)
   {
        printf("\n>>>>>> Library Home System <<<<<<\n");
        printf("\n... 1: To add a new book");
        printf("\n... 2: To view books");
        printf("\n... 3: To search book");
        printf("\n... 4: Save books to file");
        printf("\n... 5: To delete book");
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
        else if (option == 3)
        {
            handle_book_search(books_database, "print");
            continue;
        }
        else if (option == 4)
        {
            save_books_in_file(books_database);
            continue;
        }
        else if (option == 5)
        {
            handle_book_search(books_database, "delete");
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