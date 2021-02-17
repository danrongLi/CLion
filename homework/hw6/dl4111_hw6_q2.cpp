#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {

    int numTriangle;
    char charFillingTree;

    cout<<"Please enter the number of triangles you want: ";
    cin>>numTriangle;

    cout<<"Please enter the character you want to fill to tree: ";
    cin>>charFillingTree;

    printPineTree(numTriangle, charFillingTree);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol){

    int lineCount, spaceCount, symbolCount;
    int symbolCounter;

    for (lineCount = 1, symbolCount = 1; lineCount <= n; lineCount += 1, symbolCount += 2){
        for (spaceCount = 1; spaceCount <= m; spaceCount += 1){
            cout<<" ";
        }
        for (spaceCount = 1; spaceCount <= (n-lineCount); spaceCount += 1){
            cout<<" ";
        }
        for (symbolCounter = 1; symbolCounter <= symbolCount; symbolCounter += 1){
            cout<<symbol;
        }
        cout<<endl;
    }

}

void printPineTree(int n, char symbol){
    int shiftedSpaceCount, soloTriangleLineCount;
        for (shiftedSpaceCount = (n-1), soloTriangleLineCount = 2;
            shiftedSpaceCount >= 0;
            shiftedSpaceCount -= 1, soloTriangleLineCount += 1){
            printShiftedTriangle(soloTriangleLineCount, shiftedSpaceCount, symbol);
        }
    }