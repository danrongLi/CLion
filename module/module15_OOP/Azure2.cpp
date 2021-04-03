#include <iostream>

using namespace std;

class Pet {
private:
    const int _id; // Can't EVER change this outside of the initialization list.
    mutable int _age;
public:
    Pet(int id, int age) : _id {id}, _age {age} {};
    int getAge() const;
    void setAge(int age);
};

int main(int argc, char const *argv[]) {
    Pet p(10, 0);

    // Will modify age!!
    cout << p.getAge() << endl;
    cout << p.getAge() << endl;

    // Will also modify it!
    p.setAge(15);
    cout << p.getAge() << endl;
    cout << p.getAge() << endl;
}

int Pet::getAge() const {
    return _age++;
}

void Pet::setAge(int age) {
    this->_age = age;
}
