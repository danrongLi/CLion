// Introduce the idea of a deep vs shallow copy and how to use the Big 3.
#include <iostream>

using namespace std;

// Shallow copy example class
class Pet {
private:
    int _w;
    int* _pw;
public:
    // Constructor
    Pet(int w) : _w {w} {
        _pw = &_w; // Set the pointer to our location..
    }

    // Destructor to free that memory piece.
//    ~Pet() {
//        delete _pw;
//        _pw = nullptr;
//    }

    // Accessor and mutator..
    int getW() const;
    void setW(int w);

    friend ostream& operator<<(ostream& os, const Pet& pet);
};

int main(int argc, char const *argv[]) {
    Pet cat(10);
    Pet dog = cat;
    cout << "cat: " << cat << endl;
    cout << "dog: " << dog << endl;
    cat.setW(12);
    cout << "cat: " << cat << endl;
    cout << "dog: " << dog << endl;
    return 0;
}

int Pet::getW() const {
    return *_pw;
}

void Pet::setW(int w) {
    *_pw = w;
}

ostream& operator<<(ostream& os, const Pet& pet) {
    os << "_w = " << *pet._pw;
    return os;
}
