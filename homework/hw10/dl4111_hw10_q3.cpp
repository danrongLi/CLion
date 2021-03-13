#include <iostream>
#include <vector>
using namespace std;

int main1();
int main2();
int* buildIntArray(int& outArrSize);
void buildSearchArray(int intArrSize, int searchInt, const int* intArr);
vector<int> buildVector();
void searchVector(vector<int> intVector, int searchInt);

int main() {
    main2();
    return 0;
}

int main1(){

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;
    int intArrSize;

    int* intArr = buildIntArray(intArrSize);

    int searchInt;
    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchInt;

    buildSearchArray(intArrSize, searchInt, intArr);

    delete [] intArr;
    intArr = nullptr;

    return 0;
}
int main2(){

    cout<<"please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End your input by typing -1."<<endl;

    vector<int> intVector = buildVector();

    int searchInt;
    cout<<"Please enter a number you want to search."<<endl;
    cin>>searchInt;

    searchVector(intVector, searchInt);

    return 0;
}
void searchVector(vector<int> intVector, int searchInt){
    vector<int> searchVector;

    for (int i = 0; i < intVector.size(); i += 1){
        if (intVector[i] == searchInt){
            searchVector.push_back(i);
        }
    }
    cout<<searchInt<<" shows in lines ";

    for (int i = 0; i < searchVector.size(); i += 1){
        if (i < (searchVector.size()-1)){
            cout<<searchVector[i]+1<<", ";
        }
        else {
            cout<<searchVector[i]+1;
        }

    }
    cout<<"."<<endl;

}

vector<int> buildVector(){
    vector<int> intVector;
    bool seenEndOfSequence = false;
    int currentInt;
    int vectorSize = 0;

    while (!seenEndOfSequence){
        cin>>currentInt;
        if (currentInt == -1){
            seenEndOfSequence = true;
        }
        else {
            intVector.push_back(currentInt);
            vectorSize += 1;
        }
    }
    return intVector;
}

int* buildIntArray(int& outArrSize){
    int currentInt;
    int* intArr = new int[1];
    int intArrSize = 0;
    int intArrPhysicalSize = 1;

    bool seenEndOfSequence = false;
    while (!seenEndOfSequence){
        cin>>currentInt;
        if(currentInt == -1){
            seenEndOfSequence = true;
        }
        else {
            if (intArrSize == intArrPhysicalSize){
                intArrPhysicalSize *= 2;
                int* intTempArr = new int[intArrPhysicalSize];
                for (int i = 0; i < intArrSize; i += 1){
                    intTempArr[i] = intArr[i];
                }
                delete [] intArr;
                intArr = intTempArr;
            }
            intArr[intArrSize] = currentInt;
            intArrSize += 1;
        }

    }
    outArrSize = intArrSize;
    return intArr;
}

void buildSearchArray(int intArrSize, int searchInt, const int* intArr){
    int* searchArr = nullptr;
    int searchCount = 0;

    for (int i = 0; i < intArrSize; i += 1){
        if (intArr[i] == searchInt){
            searchCount += 1;
        }
    }

    searchArr = new int[searchCount];
    int arrIndex = 0;

    for (int i = 0; i < intArrSize; i += 1){
        if (intArr[i] == searchInt){
            searchArr[arrIndex] = i;
            arrIndex += 1;
        }
    }
    cout<<searchInt<<" shows in lines ";
    for (int i = 0; i < arrIndex; i += 1){
        if (i < (arrIndex-1)){
            cout<<searchArr[i]+1<<", ";
        }
        else {
            cout<<searchArr[i]+1;
        }

    }
    cout<<"."<<endl;

    delete [] searchArr;
    searchArr = nullptr;
}