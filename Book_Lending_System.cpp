#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
    bool isLent;
    int lendingDays;

    Book(int id, const string& title, const string& author)
        : id(id), title(title), author(author), isLent(false), lendingDays(0) {}
};

// Function to display all books
void displayBooks(const vector<Book>& books) {
    cout << left << setw(5) << "ID" << setw(30) << "Title" << setw(20) << "Author" 
         << setw(10) << "Status" << setw(15) << "Lending Days" << endl;
    cout << string(80, '-') << endl;
    for (const auto& book : books) {
        cout << left << setw(5) << book.id << setw(30) << book.title << setw(20) << book.author 
             << setw(10) << (book.isLent ? "Lent" : "Available")
             << (book.isLent ? to_string(book.lendingDays) : "  N/A") << endl;
    }
    cout << endl;
}

// Function to lend a book
void lendBook(vector<Book>& books, int bookId) {
    if (bookId < 0 || bookId >= books.size()) {
        cout << "Invalid book ID." << endl;
        return;
    }

    Book& book = books[bookId];
    if (book.isLent) {
        cout << "Book is already lent out." << endl;
    } else {
        book.isLent = true;
        book.lendingDays = 7;
        cout << "Book '" << book.title << "' has been lent for 7 days." << endl;
    }
}

// Function to extend lending period
void extendLending(vector<Book>& books, int bookId) {
    if (bookId < 0 || bookId >= books.size()) {
        cout << "Invalid book ID." << endl;
        return;
    }

    Book& book = books[bookId];
    if (!book.isLent) {
        cout << "Book is not currently lent out." << endl;
    } else if (book.lendingDays == 14) {
        cout << "Lending period has already been extended to the maximum of 14 days." << endl;
    } else {
        book.lendingDays = 14;
        cout << "Lending period for '" << book.title << "' has been extended to 14 days." << endl;
    }
}

// Function to return a book
void returnBook(vector<Book>& books, int bookId) {
    if (bookId < 0 || bookId >= books.size()) {
        cout << "Invalid book ID." << endl;
        return;
    }

    Book& book = books[bookId];
    if (!book.isLent) {
        cout << "Book is not currently lent out." << endl;
    } else {
        book.isLent = false;
        book.lendingDays = 0;
        cout << "Book '" << book.title << "' has been returned." << endl;
    }
}

int main() {
    // Create 100 example books
    vector<Book> books;
    for (int i = 0; i < 100; ++i) {
        books.emplace_back(i, "Book Title " + to_string(i + 1), "Author " + to_string(i + 1));
    }

    int choice;
    do {
        cout << "\nLibrary Book Lending System\n";
        cout << "1. Display all books\n";
        cout << "2. Lend a book\n";
        cout << "3. Extend lending period\n";
        cout << "4. Return a book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayBooks(books);
                break;
            case 2: {
                int bookId;
                cout << "Enter book ID to lend: ";
                cin >> bookId;
                lendBook(books, bookId);
                break;
            }
            case 3: {
                int bookId;
                cout << "Enter book ID to extend lending period: ";
                cin >> bookId;
                extendLending(books, bookId);
                break;
            }
            case 4: {
                int bookId;
                cout << "Enter book ID to return: ";
                cin >> bookId;
                returnBook(books, bookId);
                break;
            }
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
