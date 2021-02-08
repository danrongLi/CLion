/*
#######
#$   $#
# $ $ #
#  $  #
# $ $ #
#$   $#
#######
 n = 7
 */
#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Please enter an odd number which is also greater than equal to 3: "<<endl;
    cin>>n;

    int lineCount, spaceCount, hashCount;

    for (lineCount = 1; lineCount <= (n+1)/2; lineCount += 1){
        if (lineCount == 1){
            for (hashCount = 1; hashCount <= n; hashCount += 1){
                cout<<"#";
            }
        }
        else{
            cout<<"#";
            spaceCount = lineCount - 2;
            while (spaceCount > 0){
                cout<<" ";
                spaceCount -= 1;
            }
            cout<<"$";

            for (spaceCount = 1; spaceCount <= (n-2*(lineCount-2)-4); spaceCount += 1){
                cout<<" ";
            }
            if (lineCount == (n+1)/2){
                cout<<"";
            }
            else{
                cout<<"$";
            }
            spaceCount = lineCount - 2;
            while (spaceCount > 0){
                cout<<" ";
                spaceCount -= 1;
            }
            cout<<"#";
            }
        cout<<"\n";
    }

        int botLineCount, botSpaceCount, botHashCount;
        for (botLineCount = 1; botLineCount <= (n-1)/2; botLineCount += 1) {

            if (botLineCount == (n-1)/2){
                for (botHashCount = 1; botHashCount <= n; botHashCount += 1){
                    cout<<"#";
                }
            }

            else {
                cout<<"#";
                for (botSpaceCount = 1; botSpaceCount <= (n-1)/2-botLineCount-1; botSpaceCount += 1){
                    cout<<" ";
                }
                cout<<"$";

                for (botSpaceCount = 1; botSpaceCount <= ((n+1)/2-(n-2*(botLineCount-1)-(n+1)/2)); botSpaceCount+=1){
                    cout<<" ";
                }
                cout<<"$";

                for (botSpaceCount = 1; botSpaceCount <= (n-1)/2-botLineCount-1; botSpaceCount += 1){
                    cout<<" ";
                }
                cout<<"#";
            }

            cout<<"\n";

        }


    return 0;
}
