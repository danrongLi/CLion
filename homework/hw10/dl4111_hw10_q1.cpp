#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
const string SPACE = " ";

int main() {

    string sentence;

    cout<<"Please enter a sentence, with words separated by a single space:"<<endl;
    getline(cin,sentence);

    int outWordsArrSize;

    string* sentenceArr = createWordsArray(sentence,outWordsArrSize);
    cout<<outWordsArrSize<<endl;

    for (int i = 0; i < outWordsArrSize; i += 1){
        cout<<sentenceArr[i]<<" ";
    }
    cout<<endl;

    delete [] sentenceArr;
    sentenceArr = NULL;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
    string* sentenceArr = NULL;
    int wordsCount = 0;

    if (sentence.find(SPACE) == string::npos){
        wordsCount += 1;
    }
    else {
        wordsCount += 1;
        int firstSpace = sentence.find(SPACE);
        while (sentence.find(SPACE, firstSpace+1) != string::npos){
            firstSpace = sentence.find(SPACE, firstSpace+1);
            wordsCount += 1;
        }
        wordsCount += 1;
    }

    sentenceArr = new string[wordsCount];

    int initialPos = 0;
    int firstSpace = sentence.find(SPACE);
    for (int i = 0; i < wordsCount; i += 1){
        sentenceArr[i] = sentence.substr(initialPos, firstSpace-initialPos);
        initialPos = (firstSpace+1);
        if (sentence.find(SPACE, firstSpace+1) != string::npos){
            firstSpace = sentence.find(SPACE,firstSpace + 1);
        }
        else {
            firstSpace = sentence.length();
        }

    }

    outWordsArrSize = wordsCount;

    return sentenceArr;

}