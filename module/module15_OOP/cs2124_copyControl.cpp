#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        cerr<<"Base()\n";
    }
    Base(const Base& rhs){
        cerr<<"Base(const Base&)\n";
    }
    ~Base(){
        cerr<<"~Base()\n";
    }
    Base& operator=(const Base& rhs){
        cerr<<"operator=(const Base&)\n";
        return *this;
    }
};

class Derived: public Base {
public: Derived(){
    cerr<<"Derived()\n";
    }
    ~Derived(){
    cerr<<"~Derived()\n";
    }
    Derived(const Derived& rhs): Base(rhs){
    cerr<<"Derived(const Derived&)\n";
    }
    Derived& operator= (const Derived& rhs){
    cerr<<"operator=(const Derived&)\n";
    Base::operator=(rhs);
    return *this;
    }
};

int main() {
    cerr<<"Derived der:"<<endl;
    Derived der;
    cerr<<"Derived der2;"<<endl;
    Derived der2;
    cerr<<"der = der2;"<<endl;
    der = der2;
    cerr<<"main finished."<<endl;

    return 0;
}
