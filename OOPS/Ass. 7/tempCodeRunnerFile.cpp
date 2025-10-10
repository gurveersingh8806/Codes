#include <iostream>
#include <string>
#include <vector>
using namespace std;

// (iv) Global Variable: Counts total borrowing sessions across the entire program execution.
int totalSessions = 0;

// This function simulates a user's book borrowing session.
void BorrowBooks(const string& libName) {
    cout << "--- Starting new borrowing session ---" << endl;

    // (iv) Non-static local variable: Specific to this single call of BorrowBooks().
    string librarianName = libName;

    // (iv) Static local Variable: Persists across multiple calls to BorrowBooks().
    static int callCount = 0;
    callCount++;

    // Increment the global session counter each time the function is called.
    totalSessions++;

    // (i) A local class defined inside the BorrowBooks() function.
    // It can only be used within this function's scope.
    class Book {
    private:
        string title;
        int id;

    public:
        // Constructor to initialize book details
        Book(string bTitle, int bId) : title(bTitle), id(bId) {}

        // (ii) Displays book details and accesses variables from the enclosing function.
        void displayDetails() const {
            cout << "\n\tBook ID: " << id;
            cout << "\n\tBook Title: '" << title << "'";

            // Accessing all required variables from the parent function's scope
            cout << "\n\t---------------------------------";
            cout << "\n\tSession Info:";
            cout << "\n\tLibrarian on Duty: " << librarianName;
            cout << "\n\tThis is BorrowBooks() call number: " << callCount;
            cout << "\n\tTotal system-wide sessions: " << totalSessions << endl;
        }
    };

    // Create a list of books for the current session.
    vector<Book> borrowedList;
    borrowedList.push_back(Book("Dune", 101));
    borrowedList.push_back(Book("Foundation", 202));

    // (ii) Display the list before the session ends.
    cout << "Books borrowed by user in session managed by " << librarianName << ":\n";
    for (const auto& book : borrowedList) {
        book.displayDetails();
    }
    
    cout << "\n--- Ending borrowing session ---\n" << endl;
}

int main() {
    cout << "Library system is now active.\n\n";
    
    // Demonstrate two separate borrowing sessions.
    BorrowBooks("Alice");
    BorrowBooks("Bob");

    // (iii) Attempting to create a Book object here would cause a compile-time error
    // because the 'Book' class is not defined in the global scope.
    // Book myBook("Fahrenheit 451", 999); // <-- This line would be an error.

    cout << "Library system is shutting down.\n";
    cout << "Final count of total sessions today: " << totalSessions << endl;
    return 0;
}