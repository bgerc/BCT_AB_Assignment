#include <iostream>
#include <cstdlib>
using namespace std;

class Library {
    string booktitle;
    string author;
    int numberofcopies;

public:
    Library() : numberofcopies(0) {}

    void input() {
        cout << "Enter the book title: ";
        cin.ignore();
        getline(cin, booktitle);
        cout << "Enter the author name: ";
        getline(cin, author);
        cout << "Enter the number of copies of the book: ";
        cin >> numberofcopies;
    }

    void output() const {
        cout << "Name of the book: " << booktitle << endl;
        cout << "Author of the book: " << author << endl;
        cout << "Number of copies: " << numberofcopies << endl;
    }

    void addbook(int n) {
        numberofcopies += n;
        cout << "Book added successfully." << endl;
    }

    void issuebooks() {
        if (numberofcopies > 0) {
            numberofcopies--;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "No books available to issue." << endl;
        }
    }

    void returnbooks() {
        numberofcopies++;
        cout << "Book returned successfully." << endl;
    }
};

int main() {
    Library lry[100];
    int n;
    cout << "Enter the number of total  books   : " ;
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        lry[i].input();
    }

    int choice;
    while (true) {
        cout << "Enter your choice: " << endl;
        cout << "1. Show data" << endl;
        cout << "2. Add books" << endl;
        cout << "3. Issue books" << endl;
        cout << "4. Return books" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    lry[i].output();
                }
                break;
            case 2: {
                int num;
                cout << "Enter the number of books to be added: ";
                cin >> num;
                for (int i = 0; i < n; i++) {
                    lry[i].addbook(num);
                }
                break;
            }
            case 3:
                for (int i = 0; i < n; i++) {
                    lry[i].issuebooks();
                }
                break;
            case 4:
                for (int i = 0; i < n; i++) {
                    lry[i].returnbooks();
                }
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }
    return 0;
}
