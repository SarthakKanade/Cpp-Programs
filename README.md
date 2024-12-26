# Cpp-Programs
Small Programs in C++ language

1)calculator
Features:

Menu Options:
Addition: Adds two numbers.
Subtraction: Subtracts one number from another.
Multiplication: Multiplies two numbers.
Division: Divides one number by another, with a check to prevent division by zero.
Square Root: Calculates the square root of a number, ensuring the input is non-negative.
Power (x^y): Raises a number (base) to the power of another (exponent).
Exit: Allows the user to exit the program.

Error Handling:
Input Validation: Detects invalid (non-numeric) inputs and prompts the user to re-enter values.
Logical Validation:
Prevents division by zero.
Handles invalid operations like square root of negative numbers.
Uses cin.clear() and cin.ignore() to reset the input stream after invalid entries.

User-Friendly:
Displays clear instructions and error messages.
Supports continuous operation until the user chooses to exit.



2)File mannager
This program is a Library Management System implemented in C++ using object-oriented programming and file handling. It allows users to perform various operations on a library, such as adding, issuing, and returning books, as well as saving and loading library data from a file.

Key Features
1. Book Structure
A Book structure is used to represent each book in the library.
Attributes:
bookID: Unique identifier for the book.
bookName: Title of the book.
bookAuthor: Author of the book.
isIssued: Boolean flag indicating whether the book is issued or available.
issuedTo: Name of the person who issued the book.
Includes a method showBookDetails() to display a book's information.

32. Dynamic Library Management
The library is stored as a vector of Book objects, allowing for dynamic and efficient management of books.
