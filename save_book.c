#include "library.h"

/*
Save_books_in_file - Saves book list in a file
@library: Book library
*/
void save_books_in_file(book *library)
{
    FILE *file = fopen("book_database.txt", "w");
    book *curr_book = library;
    
    if (file == NULL)
    {
        perror("Unable to open file for writing");
        return;
    }

    while (curr_book != NULL)
    {
        fprintf(file, "Title: %s\nAuthor: %s\nGenre: %s\n\n",
                curr_book->title, curr_book->author, curr_book->genre);
        curr_book = curr_book->next;
    }

    fclose(file);
    printf("Books saved to file successfully.\n");
}