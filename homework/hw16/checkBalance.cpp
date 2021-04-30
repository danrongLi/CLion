#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <stack>
using namespace std;


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

//bool isBalance(const string& expression){
//    stack<char> s;
//    if (expression.empty()){
//        cout<<"You gave me an empty list! I guess it should be balanced!"<<endl;
//        return true;
//    }
//    for (int i = 0; i < expression.size(); i += 1){
//        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '('){
//            s.push(expression[i]);
//        }
//        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (!s.empty())){
//            char poppedChar = s.top();
//            s.pop();
//            switch (expression[i]) {
//                case '}':
//                    if (poppedChar != '{'){
//                        return false;
//                    }
//                    break;
//                case ']':
//                    if (poppedChar != '['){
//                        return false;
//                    }
//                    break;
//                case ')':
//                    if (poppedChar != '('){
//                        return false;
//                    }
//                    break;
//            }
//        }
//        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (s.empty())){
//            return false;
//        }
//        else{
//            continue;
//        }
//    }
//    if (!s.empty()){
//        return false;
//    }
//    else {
//        return true;
//    }
//}

int main() {
    string expr = "if (x==y){k;x=z;} if (arr[3] != [v2]){return false;}";
    if (isBalance(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}