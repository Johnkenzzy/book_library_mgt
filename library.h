#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 100

typedef struct user
{
	char name[MAX_INPUT];
	char password[MAX_INPUT];
	char confirm_pass[MAX_INPUT];
	struct user *next;
} user;

typedef struct books
{
	char title[MAX_INPUT];
	char author[MAX_INPUT];
	char genre[MAX_INPUT];
	struct books *prev;
	struct books *next;
} book;

/* USER */
user *sign_up();
user *login();
size_t get_input(char *input);
int input_get_display(user *user_acc);
void save_user_binary(const char *filename, user *data_head);
user *load_user_binary(const char *filename);

/* HOME */
int homepage(char *user);
int option_action(int option, book **books_data, const char *file);
int choose_option(void);

/* BOOKS */
book *get_book_detail();
book *add_book(book **books);
void print_books(book *books_data);
void print_format(book *book, int index);
int search_book(book *library, char *search_str,
		char *search_by, char *search_action);
void handle_book_search(book *library, char *search_action);
void delete_format(book **library, book **book_to_delete, int match);

/* STORAGE */
void save_binary(const char *filename, book *data_head);
book *load_binary(const char *filename);

/* HELPER FUNCTION 1 */
size_t item_num(book *data);


#endif /* __LIBRARY_H__ */
