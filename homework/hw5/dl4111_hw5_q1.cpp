#include <iostream>
using namespace std;

int main() {

    int n;
    int newLineCount;
    int incrementMultiple;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    for (n = 1; n <= 10; n += 1){
        for (newLineCount = n, incrementMultiple = 2; newLineCount <= n * 10;
            newLineCount = n * incrementMultiple, incrementMultiple += 1){
            cout<<newLineCount<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}
