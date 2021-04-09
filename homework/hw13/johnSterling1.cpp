#include <iostream>
#include <string>
using namespace std;

class Pet {
public:

    Pet(const string& s) : name(s) { }

    void display() const { cout << name << endl; }

protected:
    string name;
};


class Cat : public Pet {
public:

    Cat (const string& s) : Pet(s) { }

    void meow() {
        cout<<"MEOW"<<endl;
    }
};

int main() {
    Pet p("Felix");
    p.display();


    Cat c("Ratcliffe");

    c.display();

    c.meow();
    return 0;
}
