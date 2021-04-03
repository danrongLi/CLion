// Operator overloading examples, overload ALL THE THINGS!!
// Also show how friend operators work as well.
#include <iostream>
#include <string>

using namespace std;

class Pet {
private:
    int _age;
    int _weight;
    string _name;
public:
    Pet() : _age {0}, _weight {0}, _name {"Pet"} {};
    Pet(int age, int weight, string name) : _age {age}, _weight {weight}, _name {name}{};

    // Let us create a series of operators which we will then use to display data and what not.
    // First let us define the out stream/printing operator.
    friend ostream& operator<<(ostream& os, const Pet& pet);
    // What about the "in" operator?
    friend istream& operator>>(istream& is, Pet& pet);

    // What about implementing a unary operator? For example post/pre-increment.
    // Overload the var++
    Pet& operator++();
    // Overload ++var
    Pet operator++(int);

    // Overloading a binary operator
    Pet operator+(const Pet& p) {
        Pet pet;
        pet._age = this->_age + p._age;
        pet._weight = this->_weight + p._weight;
        pet._name = this->_name;
        pet._name.append(p._name);
        return pet;
    }

    // Overload the += operator for example..
    Pet operator+=(const Pet& p) {
        this->_age += p._age;
        this->_weight += p._weight;
        this->_name.append(p._name);
        return *this;
    }
};

int main(int argc, char const *argv[]) {

    // Let's create a pet and print the values out!
    Pet a(2, 10, "Alpha");
    cout << a << endl;
    cin >> a;

    // What about the post/pre-increments?
    cout << a++ << endl;

    // Adding together pets?
    Pet b(3, 5, "Bravo");

    Pet c = a + b;
    cout << b << endl;
    cout << c << endl;

    a += b;
    cout << a << endl;

    return 0;
}

// Outstream operator, since a friend, don't give it a scope of Pet class.
ostream& operator<<(ostream& os, const Pet& pet) {
    os << pet._name << " is " << pet._age << " y/o & weighs: " << pet._weight << " lbs.";
    return os;
}

// Instream operator..
istream& operator>>(istream& is, Pet& pet) {
    is >> pet._name >> pet._age >> pet._weight;
    return is;
}

// For arguments sake, we'll say it increases the age and weight by one each.
// Overload the pre-increment
Pet& Pet::operator++() {
    _age++;
    _weight++;
    return *this;
}

// Overload the post-increment
Pet Pet::operator++(int) {
    Pet temp = *this;
    this->_age++;
    this->_weight++;
    return temp;
}
