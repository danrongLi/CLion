#include <iostream>
using namespace std;

int main() {
    int n;
    int lineCount, starCount, spaceCount;
    int numberOfStars, numberOfSpaces;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    cout<<"Square"<<endl;
    for(lineCount = 1; lineCount <= n; lineCount += 1){
        // print a sequence of n stars
        for(starCount = 1; starCount <= n; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the left"<<endl;
    for(lineCount = 1; lineCount <= n; lineCount += 1){
        // print a sequence of lineCount stars
        for(starCount = 1; starCount <= lineCount; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the right"<<endl;
    for(lineCount = 1; lineCount <= n; lineCount += 1){
        // print a sequence of n-lineCount spaces
        for(spaceCount = 1; spaceCount <= (n-lineCount); spaceCount += 1)
            cout<<" ";

        // print a sequence of lineCount stars
        for(starCount = 1; starCount <= lineCount; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    cout<<endl<<"Right triangle aligned to the right in the incremental approach"<<endl;
    for(lineCount = 1, numberOfStars = 1, numberOfSpaces = (n-1);
        lineCount <= n;
        lineCount += 1, numberOfStars += 1, numberOfSpaces -= 1){
        // print a sequence of numberOfSpaces spaces
        for(spaceCount = 1; spaceCount <= numberOfSpaces; spaceCount += 1)
            cout<<" ";

        // print a sequence of numberOfStars stars
        for(starCount = 1; starCount <= numberOfStars; starCount += 1)
            cout<<"*";

        // break the line
        cout<<endl;
    }

    return 0;
}