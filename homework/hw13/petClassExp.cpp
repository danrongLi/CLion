#include <iostream>
using namespace std;

class Pet{
private:
    string name;
    int petID;
public:
    Pet(int newID = 0){petID = newID;}
    virtual void speak() const = 0;
};

class Cat: public Pet{
private:
    double whiskerLength;
public:
    Cat() : Pet(10000){}
    void speak() const {cout<<"MEOW"<<endl;}

};


class Dog: public Pet{
private:
    double earSize;
public:
    Dog():Pet(20000){}
    void speak() const {cout<<"WOOF"<<endl;}
};

int main(){
    Pet** pArray = new Pet*[3];
    pArray[0] = new Cat();
    pArray[1] = new Dog();
    pArray[2] = new Cat();
    for (int i = 0; i <3; i += 1){
        pArray[i] -> speak();
    }
}