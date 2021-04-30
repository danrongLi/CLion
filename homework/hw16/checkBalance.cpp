#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

bool isBalance(const string& expression){
    stack<char> s;
    for (int i = 0; i < expression.size(); i += 1){
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '('){
            s.push(expression[i]);
        }
        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (!s.empty())){
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
        else if ((expression[i] == '}' || expression[i] == ']' || expression[i] == ')') && (s.empty())){
            return false;
        }
    }
    return true;
}

int main() {
    string expr = "[]{}{()}";
    if (isBalance(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}