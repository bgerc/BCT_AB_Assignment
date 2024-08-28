#include <iostream>
using namespace std;

class Library {
    int number_of_copies;
    char title[10], author[10];

public:
    void new_books() {
        cout << "Enter the name of the book: ";
        cin.ignore();
        cin.getline(title, 10);
        cout << "Enter the author name: ";
        cin.getline(author, 10);
        cout << "Enter the number of copies: ";
        cin >> number_of_copies;
    }

    void issue_books() {
        if (number_of_copies > 0) {
            number_of_copies--;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "No copies available." << endl;
        }
    }

    void return_books() {
        number_of_copies++;
        cout << "Book returned successfully." << endl;
    }

    void show_books() {
        cout << "Title: " << title << ", Author: " << author << ", Copies: " << number_of_copies << endl;
    }
};

int main() {
    int c = 0, ch;
    Library* l = new Library[100]; // Allocate memory for 100 books

    while (1) {
        cout << "Enter the choice" << endl;
        cout << "1. Add new book" << endl;
        cout << "2. Issue book" << endl;
        cout << "3. Return book" << endl;
        cout << "4. Show books" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;

        switch (ch) {
            case 1:
                l[c].new_books();
                c++;
                break;
            case 2:
                if (c > 0) {
                    int book_id;
                    cout << "Enter book ID to issue (0 to " << c-1 << "): ";
                    cin >> book_id;
                    if (book_id >= 0 && book_id < c) {
                        l[book_id].issue_books();
                    } else {
                        cout << "Invalid book ID." << endl;
                    }
                } else {
                    cout << "No books available." << endl;
                }
                break;
            case 3:
                if (c > 0) {
                    int book_id;
                    cout << "Enter book ID to return (0 to " << c-1 << "): ";
                    cin >> book_id;
                    if (book_id >= 0 && book_id < c) {
                        l[book_id].return_books();
                    } else {
                        cout << "Invalid book ID." << endl;
                    }
                } else {
                    cout << "No books available." << endl;
                }
                break;
            case 4:
                for (int i = 0; i < c; i++) {
                    l[i].show_books();
                }
                break;
            case 5:
                delete[] l; // Free dynamically allocated memory
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}