#include "library.h"


/**
 * delete_format - Book printing order
 * @before_book: Previous book before the book to delete
 * Return: Nothing
*/
void delete_format(book *before_book)
{
    book *book_to_delete = before_book->next;
 
        before_book->next = book_to_delete->next;
        printf("Deleted Successfully\n");
}