#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book {
    public:
        string title, author, publication;
        int quantity;

        Book(string t, string a, string p, int q) {
            title = t;
            author = a;
            publication = p;
            quantity = q;
        }
};

class Library {
    private:
        vector<Book> books;

    public:
        void addBook(string t, string a, string p, int q) {
            Book b(t, a, p, q);
            books.push_back(b);
        }

        void displayBooks() {
            cout << "Available Books:" << endl;
            for (int i = 0; i < books.size(); i++) {
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Publication: " << books[i].publication << ", Quantity: " << books[i].quantity << endl;
            }
        }

        void searchBook(string t) {
            bool found = false;
            for (int i = 0; i < books.size(); i++) {
                if (books[i].title == t) {
                    cout << "Book Found: " << endl;
                    cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Publication: " << books[i].publication << ", Quantity: " << books[i].quantity << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Book not found." << endl;
            }
        }

        void issueBook(string t) {
            bool found = false;
            for (int i = 0; i < books.size(); i++) {
                if (books[i].title == t) {
                    if (books[i].quantity > 0) {
                        books[i].quantity--;
                        cout << "Book issued successfully." << endl;
                    } else {
                        cout << "Book is out of stock." << endl;
                    }
                    found = true;
                }
            }
            if (!found) {
                cout << "Book not found." << endl;
            }
        }

        void returnBook(string t) {
            bool found = false;
            for (int i = 0; i < books.size(); i++) {
                if (books[i].title == t) {
                    books[i].quantity++;
                    cout << "Book returned successfully." << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Book not found." << endl;
            }
        }
};

int main() {
    Library lib;
    int choice;
    string title, author, publication;
    int quantity;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Issue Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin >> title;
                cout << "Enter author: ";
                cin >> author;
                cout << "Enter publication: ";
                cin >> publication;
                cout << "Enter quantity: ";
                cin >> quantity;
                lib.addBook(title, author, publication, quantity);
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                cout << "Enter title to search: ";
                cin >> title;
                lib.searchBook(title);
                break;
            case 4:
                cout << "Enter title to issue: ";
                cin >> title;
                lib.issueBook(title);
                break;
            case 5:
                cout << "Enter title to return: ";
                cin >> title;
                lib.returnBook(title);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}