#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    int lineCount, colCount;

    for (lineCount = 1; lineCount <= n; lineCount += 1){
        if (lineCount % 2 == 0){
            for (colCount = 1; colCount <= n; colCount += 1){
                cout<<"#";
            }
        }
        else {
            for (colCount = 1; colCount <= n; colCount += 1){
                cout<<"*";
            }
        }
        cout<<"\n";
    }

    return 0;
}

