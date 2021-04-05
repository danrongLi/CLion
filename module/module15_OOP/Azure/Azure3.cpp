// Introducing the const keyword, and as a bonus, the mutable keyword and how they are used.
// Along with accessors and mutators.
#include <iostream>
#include <string>

using namespace std;

class Pet {
private:
    int _age;
    int _weight;
    string _name;
public:
    // Constructors
    Pet() : _age {0}, _weight {0}, _name {"Emerald"}{};
    Pet(int age, int weight, string name);

    // Accessors
    int getAge() const;
    int getWeight() const;
    string getName() const;

    // Mutators
    void setAge(int age);
    void setWeight(int weight);
    void setName(string name);
};

int main(int argc, char const *argv[]) {
    Pet one;
    Pet* two = new Pet(2, 10, "Ruby");

    // Print the variables, note the syntax difference!!
    cout << one.getAge() << " " << one.getWeight() << " " << one.getName() << endl;

    // These two are equivalant!!
    cout << two->getAge() << " " << two->getWeight() << " " << two->getName() << endl;
    cout << (*two).getAge() << " " << (*two).getWeight() << " " << (*two).getName() << endl;

    // Let's change some values around!
    one.setAge(15);
    one.setWeight(11);
    one.setName("Michelle");

    two->setAge(6);
    two->setWeight(24);
    two->setName("Alina");

    // Print again?
    cout << one.getAge() << " " << one.getWeight() << " " << one.getName() << endl;
    cout << two->getAge() << " " << two->getWeight() << " " << two->getName() << endl;

    // Why can't we simply do the following??
    // cout << one << endl;
    // cout << two << endl;

    delete two;
    return 0;
}

Pet::Pet(int age, int weight, string name) {
    this->_age = age;
    this->_weight = weight;
    this->_name = name;
}

// Accessors
int Pet::getAge() const {
    return this->_age;
}

int Pet::getWeight() const {
    return this->_weight;
}

string Pet::getName() const {
    return this->_name;
}

// Mutators
void Pet::setAge(int age) {
    this->_age = age;
}

void Pet::setWeight(int weight) {
    this->_weight = weight;
}

void Pet::setName(string name) {
    this->_name = name;
}
