#include "library.h"


/**
 * search_book - Searches the library for a specific book
 * @library: Shelf of books to search from
 * @search_str: String to use for the search
 * @search_by: Parameter to use to carry out the search
 * Return: Pointer to the book if found, else NULL
*/
int search_book(book *library, char *search_str, char *search_by, char *search_action)
{
    book *curr_book = library;/**slow_curr = library*/
    char *property = NULL;
    int n = 1, match = 0;

    if (!library || !search_str || !search_by)
        return (match);

    while (curr_book)
    {
        if (!strcmp(search_by, "Author") || !strcmp(search_by, "author"))
            property = curr_book->author;
        else if (!strcmp(search_by, "Title") || !strcmp(search_by, "title"))
            property = curr_book->title;
        else if (!strcmp(search_by, "Genre") || !strcmp(search_by, "genre"))
            property = curr_book->genre;
        if (strcmp(property, search_str) == 0)
        {
            ++match;
            if (strcmp(search_action, "delete") == 0)
            {
                delete_format(&library, &curr_book, match);
            }
            if (strcmp(search_action, "print") == 0)
                print_format(curr_book, match);
        }
        curr_book = curr_book->next;
        n++;
    }
    
    if (match > 0)
    {
        if (match < 2)
            printf("______________ FOUND %d BOOK _____________\n", match);
        else
            printf("______________ FOUND %d BOOKS _____________\n", match);
    }
    return (match);
}


/**
 * handle_book_search - Handles searching of the library for a specific book
 * @library: Shelf of books to search from
 * Return: Nothing
*/
void handle_book_search(book *library, char *search_action)
{
    char search_by[MAX_INPUT];
    char search_str[MAX_INPUT];

    if (!library)
        return;
 
    printf("\n>>>>>>>>>> Enter Book Property <<<<<<<<<<\n");
    printf("\n--> Example: use Author or author to search by author's name\n\n");

    printf(">>> Search by: ");
    fgets(search_by, MAX_INPUT, stdin);
    search_by[strcspn(search_by, "\n")] = '\0';

    printf(">>> search keyword: ");
    scanf(" %[^\n]", search_str);

    if (!strcmp(search_by, "Author") || !strcmp(search_by, "author"))
    {
        if (search_book(library, search_str, search_by, search_action) == 0)
        {
            printf("--> No match found, try again\n");
            return;
        }
    }
    else if (!strcmp(search_by, "Title") || !strcmp(search_by, "title"))
    {
        if (search_book(library, search_str, search_by, search_action) == 0)
        {
            printf("--> No match found, try again\n");
            return;
        }
    }
    else if (!strcmp(search_by, "genre") || !strcmp(search_by, "genre"))
    {
        if (search_book(library, search_str, search_by, search_action) == 0)
        {
            printf("--> No match found, try again\n");
            return;
        }
    }
    else
    {
        printf("--> Invalude book search property\n");
        return;
    }
}