#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Structure to store book details
struct Book 
{
    int bookID;          // Book ID
    string bookName;     // Title of the book
    string bookAuthor;   // Author of the book
    bool isIssued;       // Is the book issued or not
    string issuedTo;     // Name of the person who issued the book

    // Display book details
    void showBookDetails() const 
{
        cout << "ID: " << bookID
             << ", Name: " << bookName
             << ", Author: " << bookAuthor
             << ", Status: " << (isIssued ? "Issued to " + issuedTo : "Available") << endl;
    }
};

// Function Prototypes
void addNewBook(vector<Book>& library);
void showAllBooks(const vector<Book>& library);
void findBook(const vector<Book>& library);
void issueBook(vector<Book>& library);
void returnIssuedBook(vector<Book>& library);
void removeBook(vector<Book>& library);
void saveLibrary(const vector<Book>& library, const string& fileName);
void loadLibrary(vector<Book>& library, const string& fileName);

int main() 
{
    vector<Book> library;   // Dynamic list of books
    int menuChoice;
    const string fileName = "library_data.txt";

    // Load existing data from file
    loadLibrary(library, fileName);

    cout << "=============================\n";
    cout << " Library Management Program\n";
    cout << "=============================\n";

    do 
    {
        // Display menu options
        cout << "\n1. Add New Book";
        cout << "\n2. Show All Books";
        cout << "\n3. Search for a Book";
        cout << "\n4. Issue a Book";
        cout << "\n5. Return a Book";
        cout << "\n6. Remove a Book";
        cout << "\n7. Save and Exit";
        cout << "\nEnter your choice: ";
        cin >> menuChoice;

        switch (menuChoice) 
        {
            case 1: addNewBook(library); break;
            case 2: showAllBooks(library); break;
            case 3: findBook(library); break;
            case 4: issueBook(library); break;
            case 5: returnIssuedBook(library); break;
            case 6: removeBook(library); break;
            case 7: saveLibrary(library, fileName); cout << "Data saved. Exiting program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (menuChoice != 7);

    return 0;
}

// Function to add a new book
void addNewBook(vector<Book>& library) 
{
    Book newBook;
    cout << "\nEnter Book ID: ";
    cin >> newBook.bookID;
    cin.ignore(); // Clear input buffer
    cout << "Enter Book Name: ";
    getline(cin, newBook.bookName);
    cout << "Enter Book Author: ";
    getline(cin, newBook.bookAuthor);
    newBook.isIssued = false; // Book is available by default
    newBook.issuedTo = "";

    library.push_back(newBook);
    cout << "Book added to the library!\n";
}

// Function to show all books
void showAllBooks(const vector<Book>& library) 
{
    if (library.empty()) 
    {
        cout << "The library is empty.\n";
        return;
    }

    cout << "\nList of Books:\n";
    for (const auto& book : library) 
    {
        book.showBookDetails();
    }
}

// Function to find a book
void findBook(const vector<Book>& library) 
{
    cin.ignore();
    string searchQuery;
    cout << "\nEnter Book Name or Author to Search: ";
    getline(cin, searchQuery);

    bool found = false;
    for (const auto& book : library) {
        if (book.bookName.find(searchQuery) != string::npos || book.bookAuthor.find(searchQuery) != string::npos) {
            book.showBookDetails();
            found = true;
        }
    }

    if (!found) 
    {
        cout << "No books found matching the search.\n";
    }
}

// Function to issue a book
void issueBook(vector<Book>& library) 
{
    int bookID;
    cout << "\nEnter Book ID to Issue: ";
    cin >> bookID;

    for (auto& book : library) 
    {
        if (book.bookID == bookID) 
        {
            if (book.isIssued) 
            {
                cout << "This book is already issued to " << book.issuedTo << ".\n";
            } 
            else 
            {
                cin.ignore();
                cout << "Enter the name of the person issuing the book: ";
                getline(cin, book.issuedTo);
                book.isIssued = true;
                cout << "Book issued successfully to " << book.issuedTo << ".\n";
            }
            return;
        }
    }
    cout << "Book ID not found.\n";
}

// Function to return an issued book
void returnIssuedBook(vector<Book>& library) {
    int bookID;
    cout << "\nEnter Book ID to Return: ";
    cin >> bookID;

    for (auto& book : library) 
    {
        if (book.bookID == bookID) 
        {
            if (book.isIssued) 
            {
                book.isIssued = false;
                cout << "Book returned successfully from " << book.issuedTo << ".\n";
                book.issuedTo = "";
            } 
            else 
            {
                cout << "This book is not currently issued.\n";
            }
            return;
        }
    }
    cout << "Book ID not found.\n";
}

// Function to remove a book from the library
void removeBook(vector<Book>& library) 
{
    int bookID;
    cout << "\nEnter Book ID to Remove: ";
    cin >> bookID;

    for (auto it = library.begin(); it != library.end(); ++it) 
    {
        if (it->bookID == bookID) 
        {
            library.erase(it);
            cout << "Book removed from the library.\n";
            return;
        }
    }
    cout << "Book ID not found.\n";
}

// Function to save library data to a file
void saveLibrary(const vector<Book>& library, const string& fileName) 
{
    ofstream outFile(fileName);

    for (const auto& book : library) 
    {
        outFile << book.bookID << "\n"
                << book.bookName << "\n"
                << book.bookAuthor << "\n"
                << book.isIssued << "\n"
                << book.issuedTo << "\n";
    }

    outFile.close();
}

// Function to load library data from a file
void loadLibrary(vector<Book>& library, const string& fileName) 
{
    ifstream inFile(fileName);
    if (!inFile) 
    {
        return; // File does not exist
    }

    Book book;
    while (inFile >> book.bookID) 
    {
        inFile.ignore();
        getline(inFile, book.bookName);
        getline(inFile, book.bookAuthor);
        inFile >> book.isIssued;
        inFile.ignore();
        getline(inFile, book.issuedTo);
        library.push_back(book);
    }

    inFile.close();
    cout << "Library data loaded successfully.\n";
}
