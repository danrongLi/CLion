// Example of how a simple class and object looks, with examples of various things.
// Scope resolution operator ::
#include <iostream>
#include <string>

using namespace std;

class Pet {
private:
    int _age;
    int _weight;
    string _name;
public:
    Pet() : _age {0}, _weight {0}, _name {"Emerald"}{};
    Pet(int age, int weight, string name);
};

int main(int argc, char const *argv[]) {
    Pet p;
    Pet* p_ptr = &p;
    return 0;
}

Pet::Pet(int age, int weight, string name) {
    this->_age = age;
    this->_weight = weight;
    this->_name = name;
}
