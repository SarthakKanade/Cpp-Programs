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

=======================================================================================================

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

2. Dynamic Library Management
The library is stored as a vector of Book objects, allowing for dynamic and efficient management of books.

=======================================================================================================

3)Task Manager
This program is a simple Task Management System written in C++. It allows users to manage their tasks efficiently by performing various operations such as adding, viewing, editing, and deleting tasks. Below is a description of its key components and functionalities:

Functionalities

Add Task:
Users can create a new task by entering details like title, description, priority, deadline, and category.
Input validation ensures priority is valid (high, medium, low), and the title cannot be empty.

View All Tasks:
Displays all tasks with their details. If there are no tasks, a message is displayed.

Edit Task:
Allows editing of an existing task by entering its ID. Users can modify title, description, priority, deadline, and category.
Includes input validation for priority and ensures the title is not left empty.

Delete Task:
Deletes a task based on the ID. Provides feedback if the ID is invalid.

Mark Task as Completed:
Updates the isCompleted status of a task to true, signifying its completion.

List Tasks by Priority:
Filters tasks by the specified priority and displays them. If no tasks match, a message is shown.

List Tasks by Category:
Filters tasks by the specified category and displays them. If no tasks match, a message is shown.

Save and Load Tasks:
Tasks are saved to a file (tasks.txt) for persistence.
On startup, tasks are loaded from the file if available.

Exit:
Saves tasks to a file and exits the program.
