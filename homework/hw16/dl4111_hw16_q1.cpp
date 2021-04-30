#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;
void openFile(fstream& myFile);

template <class T>
class Stack{
public:
    void push(T newItem) {data.push_front(newItem);}
    T pop() {return data.pop_front();}
    T top() const {return *data.begin();}
    bool isEmpty() const {return data.size() == 0;}
    int size() const {return data.size();}
    void clear() {data.clear();}
private:
    list<T> data;
};


int main() {

    fstream myFile;
    openFile(myFile);

    Stack<string> myStack;




    myFile.close();

    return 0;
}

void openFile(fstream& myFile){
    string fileName;
    cout<<"Please enter your Pascal file with extension"<<endl;
    cin >> fileName;

    myFile.open(fileName);

    while (!myFile){
        cout<<"Unable to open it"<<endl;
        cout<<"Check your file name and enter again"<<endl;
        cin >> fileName;
        myFile.clear();
        myFile.open(fileName);
    }
}