#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int ALPHA_NUM = 26;
const int OFFSET = 'a' - 'A';
int printCountWords(string line);
void cleanLine(string& line);
void buildArrays(int countArr[], char alphaArr[], int arrSize, string line);

int main() {

    string line;

    cout<<"Please enter a line of text:"<<endl;
    getline(cin, line);

    int countWords = printCountWords(line);

    cout<<countWords<<"\twords"<<endl;

    cleanLine(line);

    int countArr[ALPHA_NUM];
    char alphaArr[ALPHA_NUM];

    buildArrays(countArr, alphaArr, ALPHA_NUM, line);

    for (int i = 0; i < ALPHA_NUM; i += 1){
        if (countArr[i] != 0){
            cout<<countArr[i];
            cout<<"\t"<<alphaArr[i]<<endl;
        }
    }

    return 0;
}

void buildArrays(int countArr[], char alphaArr[], int arrSize, string line){
    for (int i = 0; i < arrSize; i += 1){
        countArr[i] = 0;
        alphaArr[i] = (char)('a' + i);
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

int printCountWords(string line){
    int countWords = 0;
    for(int i = 0; i < line.length(); i += 1){
        if ((i==0) && ((line[i] >= 'A') && (line[i] <= 'z'))){
            countWords += 1;
        }
        else if (((i != 0) && (i != (line.length()-1))) && ((line[i] == ',' || line[i] == '.' || line[i] == ' ') && ((line[i-1] >= 'A') && (line[i-1] <= 'z')))){
            countWords += 1;
        }
        else if ((i == 0) && ((line[i] == ',' || line[i] == '.' || line[i] == ' '))){
            countWords += 1;
        }
        else if (((i != 0) && (i == (line.length()-1))) && ((line[i] == ',' || line[i] == '.' || line[i] == ' ') && ((line[i-1] <= 'A') || (line[i-1] >= 'z')))){
            countWords -= 1;
        }
    }
    return countWords;
}