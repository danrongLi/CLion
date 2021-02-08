//Danrong Li
//dl4111

#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Please enter a postive integer: "<<endl;
    cin>>n;

    int lineCount, xCount, oCount;
    int colCount;

    for (lineCount = 1; lineCount <= n; lineCount +=1){
        for (colCount = 1; colCount <= n; colCount += 1){
            if ((colCount%2 == 0) && (lineCount%2 != 0)){
                cout<<"O";
            }
            else if ((colCount%2 != 0) && (lineCount%2 == 0)){
                cout<<"O";
            }
            else {
                cout<<"X";
            }
        }
        cout<<"\n";
    }


    return 0;
}
