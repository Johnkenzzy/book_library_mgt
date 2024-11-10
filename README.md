Minimal Book Library Management Program
=======================================

### Overview
The Minimal Book Library Management Program is a console-based application written in C, designed to help users manage a small library of books. Users can create an account, log in, add books, view all books, search for specific books, and delete books from the library. The program provides a simple, easy-to-use interface, allowing for a straightforward library management experience.

### Features
- **User Account Creation**: New users can create an account by setting a username and password.
- **User Login**: Registered users can log in with their credentials.
- **Add New Book**: Users can add books to the library by entering the title, author, and genre.
- **View Books**: Users can view all books in the library.
- **Search Book**: Users can search for a book by title.
- **Delete Book**: Users can delete a book from the library.
- **Exit Program**: Users can exit the program at any time.

### Program Usage
To start the program, use the following command:
``bash
./library
```
### Program Workflow

```plaintext
>>>>>>>>>>>>>>> Create an Account <<<<<<<<<<<<<<<
>>> New Username: John
>>> New Password: 1234
>>> Confirm Password: 1234

--> Login Success!

WELCOME John

>>>>>> Library Home System <<<<<<

... 1: To add a new book
... 2: To view books
... 3: To search book
... 4: To delete book
... 0: To exit program

>>> 1

>>>>>>>>>> Add Book <<<<<<<<<<
>>> Book title: Obodo
>>> Author name: Mr. John
>>> Book genre: Travel

Title: Obodo
Author: Mr. John
Genre: Travel

>>> Returning to Home System...

... 1: To add a new book
... 2: To view books
... 3: To search book
... 4: To delete book
... 0: To exit program
>>> 2

>>>>> LIST OF BOOKS IN LIBRARY <<<<<

_______________[ 1 ]
Title: Obodo
Author: Mr. John
Genre: Travel

_______________[ 2 ]
Title: The Evolution
Author: Chuks U.
Genre: Scince and Nature

_______________[ 3 ]
Title: Solar Spectra
Author: Fernando Fronsi
Genre: Science Fiction

```

### Compilation
To compile the program, use the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o library *.c
```