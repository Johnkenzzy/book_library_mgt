#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_INPUT 1024


typedef struct user
{
	char *name;
	char *password;
	char *confirm_pass;
} user;


typedef struct books
{
	char title[MAX_INPUT];
    char author[MAX_INPUT];
    char genre[MAX_INPUT];
	struct books *next;
} book;


user *sign_up();
size_t get_input(char **input);
int input_get_display(user *user_acc);
int get_book_detail(book *new_book);
book *add_book(book **books);
void homepage(char **user);
void print_books(book **books_database);
void print_format(book *book, int index);
int search_book(book *library, char *search_str, char *search_by, char *search_action);
void handle_book_search(book *library, char *search_action);
void delete_format(book *before_book);

#endif /* __LIBRARY_H__ */