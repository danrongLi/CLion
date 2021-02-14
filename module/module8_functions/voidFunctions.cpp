#include <iostream>
#include <cmath>
using namespace std;

void func(int n);
int main() {

    int n = 3;
    cout<<"Before func: "<<n<<endl;
    func(n);
    cout<<"After func: "<<n<<endl;

    return 0;
}

void func(int n){
    n = 4;
    cout<<"Inside func: "<<n<<endl;
}


