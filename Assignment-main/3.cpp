#include<iostream>
using namespace std;

class Library {
    private:
        string bookTitle;
        string author;
        int noOfCopies;

    public:
        void add() {
            cout << "Enter the book title: ";
            getline(cin, bookTitle);
            cout << "Enter the author: ";
            getline(cin, author);
            cout << "Enter the number of copies: ";
            cin >> noOfCopies;
            cin.ignore();
            cout << "Book added successfully!" << endl;
        }

        void issue() {
            string temp;
            cout << "Enter the title of the book to issue: ";
            getline(cin, temp);

            if (temp == bookTitle) {
                if (noOfCopies > 0) {
                    noOfCopies--;
                    cout << "Book issued successfully!" << endl;
                } else {
                    cout << "Sorry, no copies available." << endl;
                }
            } else {
                cout << "Book not found." << endl;
            }
        }

        void returnBook() {
            string temp;
            cout << "Enter the title of the book to return: ";
            getline(cin, temp);

            if (temp == bookTitle) {
                noOfCopies++;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book not found in the library." << endl;
            }
        }
};


int main() {
    Library lib;

    while (true) {
        int choice;
        cout << "1. Add Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                lib.add();
                break;
            case 2:
                lib.issue();
                break;
            case 3:
                lib.returnBook();
                break;
            case 4:
                return 0;  // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
