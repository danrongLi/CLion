#include <iostream>
using namespace std;

class A {
public:
    A() {cout << "In A's constructor\n";}
    virtual ~A() {cout << "In A's destructor\n";}
private:
};

class C {
public:
    C() {cout << "In C's constructor\n";}
    ~C() {cout << "In C's destructor\n";}
private:
};

class B : public A {
public:
    B() {cout << "In B's constructor\n";}
    ~B() {cout << "In B's destructor\n";}
private:
    C c;
};

int main() {
    B* bPtr = new B;
    delete bPtr;
    cout << "------------------------------\n";
    A* aPtr = new B;
    delete aPtr;

    return 0;
}