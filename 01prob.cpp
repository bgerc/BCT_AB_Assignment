#include <iostream>
#include <string>
class Person {
public:
    std::string name;
    std::string dob;
    int a;
    // Add a default constructor
    Person() : name(""), dob("") {}

    Person(std::string n, std::string d) : name(n), dob(d) {}
};

int main() {
    Person* persons = new Person[100]; // assume maximum 100 persons
    int count = 0;

    std::string name, dob;

    while (true) {
        std::cout << "Enter person's name (or 'quit' to stop entering names): ";
        std::getline(std::cin, name);
        if (name == "quit") {
            break;
        }
        std::cout << "Enter person's date of birth (in YYYY-MM-DD format): ";
        std::getline(std::cin, dob);
        persons[count] = Person(name, dob);
        count++;
    }

    std::cout << "\nEnter a DOB(in YYYY-MM-DD format) to match : ";
    std::getline(std::cin, dob);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (persons[i].dob == dob) {
            std::cout << "Person with the matched date of birth: " << persons[i].name << std::endl;
            found = true;
        }
    }
         
    if (!found) {
        std::cout << "No persons have the matched date of birth." << std::endl;
    }

    delete[] persons; //free the memory

    return 0;
}