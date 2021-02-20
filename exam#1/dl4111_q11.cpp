#include <iostream>
using namespace std;

const char INITIAL_LOWERCASE = 'a';
const char INITIAL_UPPERCASE = 'A';

int main() {

    char inLetter;

    cout<<"Please enter a lower-case letter:"<<endl;
    cin>>inLetter;

    int offsetNum = inLetter - INITIAL_LOWERCASE;
    int offsetLowerUpper = INITIAL_UPPERCASE - INITIAL_LOWERCASE;

    int lineCount, numLetterCount, spaceCount;
    char currentLetter;

    for (lineCount = 1, currentLetter = 'a'; lineCount <= (offsetNum+1); lineCount += 1, currentLetter += 1){
        for (spaceCount = 1;
            spaceCount <= (offsetNum-lineCount)+1;
            spaceCount += 1){
            cout<<" ";
        }
        for (numLetterCount = 1; numLetterCount <= 2*lineCount-1; numLetterCount += 1){
            if (lineCount%2 == 0){
                cout<<(char)(currentLetter+offsetLowerUpper);
            }
            else {
                cout<<currentLetter;
            }
        }

        cout<<endl;

    }

    return 0;
}

