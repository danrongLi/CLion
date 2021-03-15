#include <iostream>
using namespace std;

int factorial(int n);

int main(){

    cout<<factorial(3)<<endl;

    return 0;
}
int factorial(int n){
    int res;
    if (n == 1){
        return 1;
    }
    else {
        res = factorial(n-1);
        res *= n;
        return res;
    }
}