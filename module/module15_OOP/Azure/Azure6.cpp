// How to make a proper deep copy.
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

    // Copy Assignment Operator
    Pet& operator=(const Pet& p) {
        // make sure you're not operating on yourself
        if(this != &p) {
            delete _pw;
            _w = p._w;
            if(p._pw != nullptr) {
                _pw = new int(*p._pw);
            } else {
                _pw = nullptr;
            }
        }
        return *this;
    }

    // Copy Constructor
    Pet(const Pet& p) {
        _w = p._w;
        // Make sure that our "other" pet's pointer to _w is not a nullptr, if it isn't, we can de-reference and use the value.
        if(p._pw != nullptr) {
            _pw = new int(*p._pw);
        } else {
            _pw = nullptr;
        }
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
    Pet turtle(5);
    Pet dog = cat;
    cout << "dog: " << dog << endl;
    cout << "cat: " << cat << endl;
    cout << "turtle: " << turtle << endl;
    // Now let's change them!
    dog.setW(15);
    cat.setW(2);
    turtle.setW(4);
    cout << "dog: " << dog << endl;
    cout << "cat: " << cat << endl;
    cout << "turtle: " << turtle << endl;
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
