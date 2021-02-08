#include <iostream>
using namespace std;

int main() {

    int maxiStar;

    cout<<"Please enter the maximum possible number of stars in a row:"<<endl;
    cin>>maxiStar;

    int lineCount, spaceCount, starCount;

    for (lineCount = 1; lineCount <= maxiStar; lineCount += 1){
        for (spaceCount = 1; spaceCount <= (maxiStar - lineCount); spaceCount += 1){
            cout<<" ";
        }
        for (starCount = 1; starCount <= lineCount; starCount += 1){
            cout<<"* ";
        }
        cout<<"\n";
    }

    int botLineCount, botSpaceCount, botStarCount;

    for (botLineCount = 1; botLineCount < maxiStar; botLineCount += 1){
        for (botSpaceCount = 1; botSpaceCount <= botLineCount; botSpaceCount += 1){
            cout<<" ";
        }
        for (botStarCount = 1; botStarCount <= (maxiStar - botLineCount); botStarCount += 1){
            cout<<"* ";
        }
        cout<<"\n";
    }


    return 0;
}
