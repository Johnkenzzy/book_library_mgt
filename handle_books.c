#include "library.h"

/**
 * get_book_detail - collects the details of the new book being created
 * @new_book: the new book the add
 * 
 * Return: 0 if successful, else 1
 */
book *get_book_detail()
{
    book *new_book = (book *)malloc(sizeof(book));

    if (!new_book)
        return (NULL);

    printf("\n>>>>>>>>>> Add Book <<<<<<<<<<\n\n");

    printf(">>> Book title: ");
    fgets(new_book->title, MAX_INPUT, stdin);
    new_book->title[strcspn(new_book->title, "\n")] = '\0'; 

    printf(">>> Author name: ");
    fgets(new_book->author, MAX_INPUT, stdin);
    new_book->author[strcspn(new_book->author, "\n")] = '\0';

    printf(">>> Book genre: ");
    fgets(new_book->genre, MAX_INPUT, stdin);
    new_book->genre[strcspn(new_book->genre, "\n")] = '\0';

    printf("\nTitle: %s\n", (new_book)->title);
    printf("Author: %s\n", (new_book)->author);
    printf("Genre: %s\n", (new_book)->genre);

    return (new_book);
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
    book *new_book = malloc(sizeof(book));

    if (!new_book)
        return (NULL);

    new_book = get_book_detail();
    new_book->next = NULL;

    if (*books == NULL)
        *books = new_book;
    else
    {
        temp = *books;
        while (temp->next)
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
void print_books(book *books_data)
{
    book *temp = books_data;
    int index = 1;
    
    printf("\n>>>>> LIST OF BOOKS IN LIBRARY <<<<<\n");
    if (!books_data)
    {
        printf("\n--> Sorry! You haven't added any books\n... Add some\n");
        return;
    }

    while (temp != NULL)
    {
        print_format(temp, index++);
        temp = temp->next;
    }
}


/**
 * print_format - Book printing order
 * @book: Book to print
 * @index: Index of book in the list of books
 * Return: Nothing
*/
void print_format(book *book, int index)
{
        printf("\n_______________[ %d ]\n", index);
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Genre: %s\n", book->genre);
}


/**
 * reload_books - creates and add new book
 * @books: books storage data structure
 * 
 * Return: pointer to the newly added book
 */
/*book *reload_book(book **books, book *each_book)
{
    book *temp;
    book *new_book = (book *)malloc(sizeof(book));

    if (new_book == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return (NULL);
    }

    new_book = each_book;
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
}*/