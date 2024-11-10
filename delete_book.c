#include "library.h"


/**
 * delete_format - Book printing order
 * @library: Book library to delete from
 * @book_to_delete: Book to be deleted
 * Return: Nothing
*/
void delete_format(book **library, book **book_to_delete, int match)
{
    if ((*book_to_delete)->prev != NULL)
       (*book_to_delete)->prev->next = (*book_to_delete)->next;
    else
        *library = (*book_to_delete)->next;
    
    if ((*book_to_delete)->next != NULL)
        (*book_to_delete)->next->prev = (*book_to_delete)->prev;

    /*free(*book_to_delete);*/
    print_format(*book_to_delete, match);
    /**book_to_delete = NULL;*/
    printf("Deleted Successfully\n");
}