#include <iostream>
using namespace std;

int main() {

    int n;
    int newLineCount;
    int incrementMultiple;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    for (int i = 1; i <= n; i += 1){
        for (newLineCount = i, incrementMultiple = 2; newLineCount <= i * n;
            newLineCount = i * incrementMultiple, incrementMultiple += 1){
            cout<<newLineCount<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}
