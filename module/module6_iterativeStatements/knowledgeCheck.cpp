#include <iostream>
using namespace std;

int main(){

    int a = 0;
    int iterations = 0;

    while (a < 25)
    {a += 2;
        iterations ++;
    }

    cout << a << endl;
    cout << iterations;
    return 0;
}