#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"Please a positive integer: ";
    cin>>n;

    int counter = 1;
    while (counter <= n){
        cout<<counter<<endl;
        counter++;
    }

    return 0;
}
