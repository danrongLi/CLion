// Example of Basic Inheritance & introducing the protected keyword
#include <iostream>
#include <string>

using namespace std;

// Base class.
class Pet {
private:
    string _name;
protected:
    int _age;
public:
    Pet() : _name {""}, _age {0} {};
    Pet(string name, int age) : _name {name}, _age {age} {};
    string makeSound() {
        return "Default Animal Noise!";
    }
};

// Inherited class.
class Cat : public Pet {
private:
    char _gender;
public:
    Cat(char gender, string name, int age) : _gender {gender} {
        Pet(name, age);
    }
    char getGender() const {
        return _gender;
    }

    // Can't do this!
    /*
    string getName() const {
        return _name;
    }
    */

    // Can do this!
    int getAge() const {
        return _age;
    }

    // What happens if this exists vs doesn't exist?
    /*
    string makeSound() {
        return "Meow!";
    }
    */
};

int main(int argc, char const *argv[]) {
    Cat cat('F', "Clara", 10);
    cout << cat.makeSound() << endl;
    // can call the base version if you really wanted to as well..
    // cout << cat.Pet::makeSound() << endl;
    return 0;
}
