#include <string>
#include <iostream>
using namespace std;

// A simple Person class.
class Person {
public:
    Person(const string& aName): name(aName) {}
protected:
    string name;
};

class Instructor :
        virtual public Person {
public:
    Instructor(const string& aName): Person(aName) {}
};

class Student:
        virtual public Person {
public:
    Student(const string& aName): Person(aName) {}
};

class TA : public Instructor, public Student {
public:
    TA(const string& myName) :
            Person(myName),
            Instructor(myName), Student(myName) {}
    void display(ostream& os = cout) const {
        os << Person::name << endl;
        os << Student::Person::name << endl;
        os << Instructor::Person::name << endl;
    }
private:
};

int main() {
    TA chirag("Chirag Chhatriwala");
    chirag.display();
}
