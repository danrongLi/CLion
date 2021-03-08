#include <iostream>
#include <string>
using namespace std;

const int ALPHA_NUM = 26;
const int OFFSET = 'a' - 'A';
void cleanLine(string& line);
void buildArrays(int countArr[], string line, int arrSize);
void checkAnagrams(const int countArrSecond[], const int countArr[]);

int main() {

    string line;
    string lineSecond;

    cout<<"Please enter the first string:"<<endl;
    getline(cin, line);

    cleanLine(line);

    int countArr[ALPHA_NUM];
    int countArrSecond[ALPHA_NUM];

    buildArrays(countArr, line, ALPHA_NUM);

    cout<<"Please enter the second string:"<<endl;
    getline(cin, lineSecond);
    cleanLine(lineSecond);
    buildArrays(countArrSecond, lineSecond, ALPHA_NUM);

    checkAnagrams(countArrSecond, countArr);

    return 0;
}

void checkAnagrams(const int countArrSecond[], const int countArr[]){
    bool isAnagrams = true;

    for (int i = 0; ((i < ALPHA_NUM) && (isAnagrams)); i += 1){
        if (countArrSecond[i] != countArr[i]){
            isAnagrams = false;
        }
    }

    if (isAnagrams){
        cout<<"Yes, they are anagrams"<<endl;
    }
    else {
        cout<<"NO, they are not anagrams"<<endl;
    }
}

void buildArrays(int countArr[], string line, int arrSize){

    for (int i = 0; i < arrSize; i += 1){
        countArr[i] = 0;

    }

    for (int i = 0; i < line.length(); i += 1){
        if (line[i] >= 'a' && line[i] <= 'z'){
            countArr[line[i]-'a'] += 1;
        }
    }
}

void cleanLine(string& line){
    for (int i = 0; i < line.length(); i += 1){
        if (line[i] >= 'A' && line[i] <= 'Z'){
            line[i] += OFFSET;
        }
    }
}
