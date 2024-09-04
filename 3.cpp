#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Library
{
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    void input()
    {
        cout << "Enter The Book Title: ";
        cin.ignore();
        getline(cin, bookTitle);
        cout << "Enter the Author Name: ";
        getline(cin, author);
        cout << "Enter The number of Copies: ";
        cin >> numberOfCopies;
    }

    void output() const
    {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author Name: " << author << endl;
        cout << "The number of Copies: " << numberOfCopies << endl;
    }

    string getTitle() const
    {
        return bookTitle;
    }

    bool issueBook()
    {
        if (numberOfCopies > 0)
        {
            numberOfCopies--;
            return true;
        }
        return false;
    }

    void returnBook()
    {
        numberOfCopies++;
    }
};

int main()
{
    int n;
    cout << "Enter the Number of Books to ADD: ";
    cin >> n;

    vector<Library> books(n);
    for (int i = 0; i < n; ++i)
    {
        books[i].input();
    }

    string name;
    cout << "\n"
         << endl;
    cout << "\n"
         << endl;
    cout << "\n"
         << endl;

    cout << " __________________________________________________________________________" << endl;

    cout << "Enter the book you want to issue: ";
    cin.ignore();
    getline(cin, name);

    bool issued = false;
    for (int i = 0; i < n; ++i)
    {
        if (books[i].getTitle() == name)
        {
            if (books[i].issueBook())
            {
                cout << "Book issued successfully.\n";
                cout << " __________________________________________________________________________" << endl;
                cout << "\n"
                     << endl;
                cout << "\n"
                     << endl;
                cout << "\n"
                     << endl;
            }
            else
            {
                cout << "Book is out of stock.\n";
                cout << " __________________________________________________________________________" << endl;
                cout << "\n"
                     << endl;
                cout << "\n"
                     << endl;
                cout << "\n"
                     << endl;
            }
            issued = true;
            break;
        }
    }
    if (!issued)
    {
        cout << "Book not found.\n";
        cout << " __________________________________________________________________________" << endl;
        cout << "\n"
             << endl;
        cout << "\n"
             << endl;
        cout << "\n"
             << endl;
    }
    cout << "\n"
         << endl;
    cout << "\n"
         << endl;

    cout << "\n"
         << endl;

    cout << " __________________________________________________________________________" << endl;

    cout << "Enter the book you want to return: ";
    getline(cin, name);

    bool returned = false;
    for (int i = 0; i < n; ++i)
    {
        if (books[i].getTitle() == name)
        {
            books[i].returnBook();
            cout << "Book returned successfully.\n";
            cout << " __________________________________________________________________________" << endl;
            cout << "\n"
                 << endl;
            cout << "\n"
                 << endl;
            cout << "\n"
                 << endl;

            returned = true;
            break;
        }
    }
    if (!returned)
    {
        cout << "Book not found in the library.\n";
        cout << " __________________________________________________________________________" << endl;
        cout << "\n"
             << endl;
        cout << "\n"
             << endl;
        cout << "\n"
             << endl;
    }
    cout << " __________________________________________________________________________" << endl;

    cout << "\nLibrary Inventory:\n";
    cout << " __________________________________________________________________________" << endl;

    for (const auto &book : books)
    {
        book.output();
        cout << "\n"
             << endl;
        cout << "\n"
             << endl;
    }

    cout << " __________________________________________________________________________" << endl;

    return 0;
}
