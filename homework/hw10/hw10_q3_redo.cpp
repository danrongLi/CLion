#include <iostream>
#include <vector>
using namespace std;

int main1();
int main2();
vector<int> createIntArr();
void lookSearch(vector<int> sequenceArr, int searchInt);
int* sequenceArray(int& sequenceArrSize);
void searchArray(int sequenceArrSize, int searchInt, int* sequenceArr);

int main(){
    main1();
    return 0;
}
int main2(){
    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;
    vector<int> sequenceArr = createIntArr();

    cout<<"Please enter a number you want to search."<<endl;
    int searchInt;
    cin>>searchInt;
    lookSearch(sequenceArr,searchInt);

    return 0;
}
vector<int> createIntArr(){
    vector<int> sequenceArr;
    bool seenEndOfSequence = false;
    int currentInt;
    while(!seenEndOfSequence){
        cin>>currentInt;
        if (currentInt == -1){
            seenEndOfSequence = true;
        }
        else {
            sequenceArr.push_back(currentInt);
        }
    }
    return sequenceArr;
}
void lookSearch(vector<int> sequenceArr, int searchInt){
    vector<int> searchArr;
    for (int i = 0; i < sequenceArr.size(); i += 1){
        if (sequenceArr[i] == searchInt){
            searchArr.push_back(i);
        }
    }
    cout<<searchInt<<" shows in lines ";
    for (int i = 0; i < searchArr.size(); i += 1){
        if (i == (searchArr.size()-1)){
            cout<<searchArr[i]+1<<".";
        }
        else {
            cout<<searchArr[i]+1<<", ";
        }
    }
    cout<<endl;
}
int main1(){

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;
    int sequenceArrSize;
    int* sequenceArr = sequenceArray(sequenceArrSize);

    cout<<"Please enter a number you want to search."<<endl;
    int searchInt;
    cin>>searchInt;

    searchArray(sequenceArrSize, searchInt, sequenceArr);

    delete [] sequenceArr;
    sequenceArr = nullptr;

    return 0;
}

void searchArray(int sequenceArrSize, int searchInt, int* sequenceArr){
    int countSearch = 0;
    for (int i = 0; i < sequenceArrSize; i += 1){
        if (sequenceArr[i] == searchInt){
            countSearch += 1;
        }
    }
    int* searchArr = new int[countSearch];
    int currentIndex = 0;
    for (int i = 0; i < sequenceArrSize; i += 1){
        if (sequenceArr[i] == searchInt){
            searchArr[currentIndex] = i;
            currentIndex += 1;
        }
    }
    cout<<searchInt<<" shows in lines ";
    for (int i = 0; i < countSearch; i += 1){
        if (i == (countSearch-1)){
            cout<<searchArr[i]+1<<".";
        }
        else {
            cout<<searchArr[i]+1<<", ";
        }
    }
    cout<<endl;

    delete [] searchArr;
    searchArr = nullptr;
}

int* sequenceArray(int& sequenceArrSize){
    int currentInt;
    bool seenEndOfSeq = false;

    sequenceArrSize = 0;
    int sequencePhysical = 1;
    int* sequenceArr = new int[sequencePhysical];

    while (!seenEndOfSeq){
        cin>>currentInt;
        if (currentInt == -1){
            seenEndOfSeq = true;
        }
        else {
            if (sequenceArrSize == sequencePhysical){
                sequencePhysical *= 2;
                int* largerArr = new int[sequencePhysical];
                for (int i = 0; i < sequenceArrSize; i += 1){
                    largerArr[i] = sequenceArr[i];
                }
                delete [] sequenceArr;
                sequenceArr = largerArr;

            }
            sequenceArr[sequenceArrSize] = currentInt;
            sequenceArrSize += 1;
        }
    }
    return sequenceArr;
}