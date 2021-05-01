#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;
void openFile(fstream& myFile);
bool isBalance(const string& expression);
bool isBalanceEntire(fstream& myFile);

template <class T>
class Stack{
public:
    void push(T newItem) {data.push_front(newItem);}
    void pop() {data.pop_front();}
    T top() const {return *data.begin();}
    bool isEmpty() const {return data.empty();}
    int size() const {return data.size();}
    void clear() {data.clear();}
private:
    list<T> data;
};

int main() {

    fstream myFile;
    openFile(myFile);

    bool checkEntire = isBalanceEntire(myFile);


    if (checkEntire){
        cout<<"Balanced!"<<endl;
    }
    else {
        cout<<"NOT Balanced!"<<endl;
    }

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

bool isBalance(const string& expression){
    Stack<char> s;
    if (expression.empty()){
        cout<<"You gave me an empty list! I guess it should be balanced!"<<endl;
        return true;
    }
    for (int i = 0; i < expression.size(); i += 1){
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '('){
            s.push(expression[i]);
        }
        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (!s.isEmpty())){
            char poppedChar = s.top();
            s.pop();
            switch (expression[i]) {
                case '}':
                    if (poppedChar != '{'){
                        return false;
                    }
                    break;
                case ']':
                    if (poppedChar != '['){
                        return false;
                    }
                    break;
                case ')':
                    if (poppedChar != '('){
                        return false;
                    }
                    break;
            }
        }
        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (s.isEmpty())){
            return false;
        }
        else{
            continue;
        }
    }
    if (!s.isEmpty()){
        return false;
    }
    else {
        return true;
    }
}

bool isBalanceEntire(fstream& myFile){
    Stack<string> myStack;
    string current;
    string middleFile;
    bool addedMiddle = false;
    if (!myFile){
        cout<<"You gotta be kidding me"<<endl;
        return false;
    }
    while (myFile>>current){
        if (current == "begin"){
            myStack.push(current);
            if (addedMiddle){
                bool checkPrevious = isBalance(middleFile);
                if(!checkPrevious){
                    return false;
                }
                else {
                    middleFile = "";
                    addedMiddle = false;
                }
            }

        }
        else if ((current == "end") && (!myStack.isEmpty())){
            string popped = myStack.top();
            myStack.pop();
        }
        else if ((current == "end") && (myStack.isEmpty())){
            return false;
        }
        else {
            middleFile += current;
            addedMiddle = true;
        }

    }
    if (!myStack.isEmpty()){
        return false;
    }
    else {
        if (addedMiddle){
            bool checkPrevious = isBalance(middleFile);
            if(!checkPrevious){
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return true;
        }
    }

}