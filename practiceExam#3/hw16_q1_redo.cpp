#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;
void openFile(fstream& myFile);
bool checkBalance(const string& expression);
bool checkEntire(fstream& myFile);

template <class T>
class Stack{
public:
    void push(T newItem){data.push_front(newItem);}
    void pop(){data.pop_front();}
    T top(){return *data.begin();}
    int size(){return data.size();}
    void clear(){data.clear();}
    bool isEmpty() {return size() == 0;}
private:
    list<T> data;
};

int main(){

    fstream myFile;
    openFile(myFile);

    bool result = checkEntire(myFile);
    if (result){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }

    myFile.close();

    return 0;
}

bool checkEntire(fstream& myFile){
    Stack<string> myStack;
    string current;
    string middle;
    bool addedMiddle = false;
    while (myFile >> current){
        if (current == "begin" || current == "BEGIN"){
            myStack.push(current);
            if (addedMiddle){
                bool previous = checkBalance(middle);
                if (previous){
                    addedMiddle = false;
                    middle = "";
                }
                else {
                    return false;
                }
            }
        }
        else if ((current == "end" || current == "END") && !myStack.isEmpty()){
            myStack.pop();
        }
        else if ((current == "end" || current == "END") && myStack.isEmpty()){
            return false;
        }
        else {
            middle += current;
            addedMiddle = true;
        }
    }
    if (!myStack.isEmpty()){
        return false;
    }
    else {
        if (addedMiddle){
            bool previous = checkBalance(middle);
            if (!previous){
                return false;
            }
        }
        return true;
    }
}

bool checkBalance(const string& expression){
    Stack<char> myStack;
    for (int i = 0; i < expression.size(); i += 1){
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '('){
            myStack.push(expression[i]);
        }
        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (!myStack.isEmpty())){
            char currentTop = myStack.top();
            myStack.pop();
            switch (expression[i]) {
                case '}':
                    if (currentTop != '{'){
                        return false;
                    }
                    break;
                case ']':
                    if (currentTop != '['){
                        return false;
                    }
                    break;
                case ')':
                    if (currentTop != '('){
                        return false;
                    }
                    break;
            }
        }
        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (myStack.isEmpty())){
            return false;
        }
        else {
            continue;
        }
    }
    if (!myStack.isEmpty()){
        return false;
    }
    else {
        return true;
    }
}

void openFile(fstream& myFile){
    string name;
    cout<<"Enter file name"<<endl;
    cin>>name;

    myFile.open(name);
    while(!myFile){
        cout<<"Wrong name, enter again"<<endl;
        cin>>name;
        myFile.clear();
        myFile.open(name);
    }

}