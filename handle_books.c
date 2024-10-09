#include "main.h"

/**
 * get_book_detail - collects the details of the new book being created
 * @new_book: the new book the add
 * 
 * Return: 0 if successful, else 1
 */
int get_book_detail(book *new_book)
{
    printf("\n>>>>>>>>>> Add Book <<<<<<<<<<\n\n");

    printf(">>> Book title: ");
    fgets(new_book->title, MAX_TITLE, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = '\0'; 

    printf(">>> Author name: ");
    fgets(new_book->author, MAX_AUTHOR, stdin);
    new_book->author[strcspn(new_book->author, "\n")] = '\0';

    printf(">>> Book genre: ");
    fgets(new_book->genre, MAX_GENRE, stdin);
    new_book->genre[strcspn(new_book->genre, "\n")] = '\0';

    printf("\nTitle: %s\n", (new_book)->title);
    printf("Author: %s\n", (new_book)->author);
    printf("Genre: %s\n", (new_book)->genre);

    return (0);
}


/**
 * add_book - creates and add new book
 * @books: books storage data structure
 * 
 * Return: pointer to the newly added book
 */
book *add_book(book **books)
{
    book *temp;
    book *new_book = (book *)malloc(sizeof(book));

    if (new_book == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return (NULL);
    }

    get_book_detail(new_book);
    new_book->next = NULL;

    if (*books == NULL)
        *books = new_book;
    else
    {
        temp = *books;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_book;
    }

    return (new_book);
}

/**
 * print_books - Prints all books in the list
 * @books: Pointer to the head of the book list
 */
void print_books(book **books) {
    book *temp = *books;
    int index = 1;
    
    printf("LIST OF BOOKS IN LIBRARY\n");
    if (temp == NULL)
    {
        printf("\n--> Sorry! You haven't added any books\n... Add some\n");
        return;
    }

    while (temp != NULL)
    {
        printf("\n_______________[ %d ]\n", index++);
        printf("Title: %s\n", temp->title);
        printf("Author: %s\n", temp->author);
        printf("Genre: %s\n", temp->genre);
        temp = temp->next;
    }
}


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