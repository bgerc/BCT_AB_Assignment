#include<iostream>
using namespace std;
class Library{
    string bookTitle,author;
    int numberOfCopies;
    public:
    void getData(){
        cout << "Enter Book Title: ";
        getline(cin >> ws, bookTitle);
        cout << "Enter author name: ";
        getline(cin >>ws, author);
        cout << "Enter number of copies: ";
        cin >> numberOfCopies;
    }
    void addBook(int n){
        numberOfCopies += n;
    }
    void issueBook(){
        int count;
        cout << "Enter number of issused book: ";
        cin >> count;
        numberOfCopies -= count;
    }
    void returnBook(){
        int count;
        cout << "Enter the number of book returned: ";
        cin >> count;
        numberOfCopies += count;
    }
    void displayBookInfo(){
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies: " << numberOfCopies << endl;
    }
};
int main(){
    Library obj;
    while(true){
        int c;
        cout << "Enter choise(1,2,3,4): " << endl;
        cout << "1.Add Book\n2.Issue Book\n3.Return Book\n4.Exit" << endl;
        cin >> c;
        if(c==1){
            int a;
            cout << "Enter number of book to add: ";
            cin >> a;
            obj.addBook(a);
            obj.displayBookInfo();
        }
        else if(c==2){
            obj.issueBook();
            obj.displayBookInfo();
        }
        else if(c==3){
            obj.returnBook();
            obj.displayBookInfo();
        }
        else if(c==4){
            cout << "Thank you for using our service";
            return 0;
        }
        else{
            cout << "Please Enter valid input" << endl;
        }
    }
    return 0;

}
