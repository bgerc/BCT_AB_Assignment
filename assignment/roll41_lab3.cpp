#include <iostream>
#include <string.h>
using namespace std;

class Library {
public:
    char bookTitle[50];
    char author[50];
    int numberOfCopies;

    Library(const char* bookTitle, const char* author, int numberOfCopies) {
        strcpy(this->bookTitle, bookTitle);
        strcpy(this->author, author);
        this->numberOfCopies = numberOfCopies;
    }

    void addBook(int copies) {
        numberOfCopies += copies;
    }

    void issueBook(int copies) {
        if (numberOfCopies >= copies) {
            numberOfCopies -= copies;
        } else {
            cout << "Not enough copies available!" << std::endl;
        }
    }

    void returnBook(int copies) {
        numberOfCopies += copies;
    }
};

int main() {
    Library book1("123", "Manav", 3);                           //3ta book xa =3

    book1.addBook(3);
    cout << "Number of copies after adding: " << book1.numberOfCopies << std::endl;           //3ta add vo =6

    book1.issueBook(2);
    cout << "Number of copies after issuing: " << book1.numberOfCopies << std::endl;          //2ta issue vo =4

    book1.returnBook(1);
    cout << "Number of copies after returning: " << book1.numberOfCopies << std::endl;          //euta return vo 5

    return 0;
}


