#include <iostream>
#include <string>
using namespace std;

const char X = 'x';
const string SPACE = " ";
string getWord(string str, string stopSpace, int& startingPosition, int& nextPosition);
void printLine(string lineOfText);

int main() {

    string lineOfText;

    cout<<"Please enter a line of text:"<<endl;
    getline(cin, lineOfText);

    printLine(lineOfText);

    return 0;

}

string getWord(string str, string stopSpace, int& startingPosition, int& nextPosition){
    nextPosition = str.find(stopSpace, startingPosition+1);
    string currentWord = str.substr(startingPosition+1, nextPosition-(startingPosition+1));
    startingPosition = nextPosition;
    return currentWord;
}

void printLine(string lineOfText){
    string currentWord;
    int startingPosition = -1;
    int nextPosition = 0;

    while (nextPosition != string::npos){
        currentWord = getWord(lineOfText, SPACE, startingPosition, nextPosition);
        bool isLetter = false;
        for (int i = 0; (i < currentWord.length() && !isLetter); i += 1){
            if ((currentWord[i] >= 'A') && (currentWord[i] <= 'z')){
                isLetter = true;
            }
        }
        if (isLetter){
            cout<<currentWord<<" ";
        }
        else {
            for (int i = 0; i < currentWord.length(); i += 1){
                currentWord[i] = X;
            }
            cout<<currentWord<<" ";
        }
    }
    cout<<endl;
}

