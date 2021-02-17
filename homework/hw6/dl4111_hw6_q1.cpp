#include <iostream>
using namespace std;

int fib(int n);

int main() {

    int userInput;

    cout<<"Please enter a positive integer: ";
    cin>>userInput;

    int fibResult = fib(userInput);
    cout<<fibResult<<endl;

    return 0;
}

int fib(int n){
    if ((n == 1) || (n == 2)){
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}