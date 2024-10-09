#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_GENRE 100


typedef struct user
{
	char *name;
	char *password;
	char *confirm_pass;
} user;


typedef struct books
{
	char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char genre[MAX_GENRE];
	struct books *next;
} book;

typedef struct books_database
{
	book *details;
	struct books_database *next;
} b_data;

user* add_user();
user *sign_up();
size_t get_input(char **input);
int input_get_display(user *user_acc);
int get_book_detail(book *new_book);
book *add_book(book **books);
void homepage(char **user);
void print_books(book **books_database);

#endif /* __MAIN_H__ */
