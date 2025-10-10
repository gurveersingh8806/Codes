#include <iostream>
#include <string>
#include <vector>
using namespace std;

int totalSessions = 0;

void BorrowBooks(const string& libName) {

    string librarian = libName;

    static int callCount = 0;
    callCount++;

    class Book {
        string title;
        int id;


    public:
        Book(string t, int i) : title(t), id(i) {}

        void display(int sessionNum, string librarianName, int totalSess) {
            cout << "Book Title: " << title << ", ID: " << id << endl;
            cout << "Librarian: " << librarianName << endl;
            cout << "Session Number: " << sessionNum << endl;
            cout << "Total Sessions: " << totalSess << endl;
            cout << "----------------------------------------" << endl;
        }
    };

    vector<Book> borrowedBooks;

    int n;
    cout << "\nEnter number of books to borrow: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string title;
        int id;
        cout << "Enter title of book " << i + 1 << ": ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter ID of book " << i + 1 << ": ";
        cin >> id;
        borrowedBooks.emplace_back(title, id);
    }
    totalSessions++;

    cout << "\n===== Borrowed Books in This Session =====\n";
    for (auto& b : borrowedBooks) {
        b.display(callCount, librarian, totalSessions);
    }

    cout << "===== Session Ended =====\n\n";
}

int main() {
    BorrowBooks("Mr. Sharma");
    BorrowBooks("Ms. Kapoor");
    return 0;
}
