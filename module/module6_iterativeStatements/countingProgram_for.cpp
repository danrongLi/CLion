#include <iostream>
using namespace std;

int main() {

    int n;
    int counter;

    cout<<"Please enter a positive integer: ";
    cin>>n;

    for (counter = 1; counter <= n; counter += 1){
        cout<<counter<<endl;
    }

    return 0;
}
