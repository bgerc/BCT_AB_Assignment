/*
Define a class Library with bookTitle, author, and numberOfCopies as data
members. Implement methods to add new books, issue books, and return books.
Ensure that the number of copies is appropriately updated for each operation.
*/

#include<iostream>
#include<string>

using namespace std;

class BookStore {
    string title;
    string authorName;
    int copiesAvailable = 0;

public:
    void enterDetails() {
        cin.ignore();  // Clear any newline character left in the input buffer
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, authorName);
        cout << "Enter the number of available copies: ";
        cin >> copiesAvailable;
    }

    void displayDetails() const {
        cout << "Book Title: " << title << endl
             << "Author: " << authorName << endl
             << "Available Copies: " << copiesAvailable << endl;
    }

    void addCopies(int count) {
        copiesAvailable += count;
        cout << count << " copies added successfully." << endl;
    }

    void lendBook() {
        if (copiesAvailable > 0) {
            copiesAvailable--;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "Sorry, this book is currently unavailable." << endl;
        }
    }

    void receiveBook() {
        copiesAvailable++;
        cout << "Book returned successfully." << endl;
    }
};

int main() {
    BookStore store;
    store.enterDetails();

    int choice, count;

    while (true) {
        system("cls");  // Clear the screen (use "clear" on Linux/Mac)
        cout << "Library Management System\n";
        cout << "1. View Book Information\n";
        cout << "2. Add Copies\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.displayDetails();
                break;
            case 2:
                cout << "Enter the number of copies to add: ";
                cin >> count;
                store.addCopies(count);
                break;
            case 3:
                store.lendBook();
                break;
            case 4:
                store.receiveBook();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();  // Wait for the user to press Enter
    }

    return 0;
}
