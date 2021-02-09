#include <iostream>
using namespace std;

int main() {

    int n;
    cout<<"Please enter an integer, greater or equal to 2:"<<endl;
    cin>>n;

    int lineCount, spaceCount;

    for (lineCount = 1; lineCount <= n; lineCount += 1){
        spaceCount = lineCount - 1;
        while(spaceCount > 0){
            cout<<" ";
            spaceCount -= 1;
        }
        cout<<"*";
        if (lineCount == 1){
            for (spaceCount = 1; spaceCount <= (2*n-1)-1; spaceCount += 1){
                cout<<"*";
            }
        }
        else if (lineCount == n){
                cout<<"\n";
            }
        else {
            for (spaceCount = 1; spaceCount <= (2*n-1-2-2*(lineCount-1)); spaceCount += 1){
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}

