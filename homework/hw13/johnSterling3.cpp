#include <iostream>
#include <string>
using namespace std;

class Pet {
public:

    Pet(const string& s) { name = s; }


    virtual void displayDetailed() const {
        cout << "Pet: " << name << endl;
    }
protected:
    string name;
};

class Cat : public Pet {
public:
    Cat (const string& s) : Pet(s) { }

    void displayDetailed() const {
        cout << "Cat: " << name << endl;
    }
};

int main() {
    Pet p("Felix");
    p.displayDetailed();
    Cat c("Ratcliffe");
    c.displayDetailed();

    cout << endl << "Playing with containers of Pets\n\n";

    Pet myPets[2] = {p, c};
    for (int i = 0; i < 2; i++)
        myPets[i].displayDetailed();

    Pet* myPetPointers[2];
    myPetPointers[0] = &p;
    myPetPointers[1] = &c;
    for (int j = 0; j < 2; j++)
        myPetPointers[j]->displayDetailed();
    return 0;
}