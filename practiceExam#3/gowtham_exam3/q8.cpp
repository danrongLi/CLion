#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void mergeSort(vector<int>& v, int start, int end);
void merge(vector<int>& v, int start, int middle, int end);
bool binarySearch(vector<int> v, int start, int end, int val);

void openFile(ifstream& file);

int main(){
    ifstream file;
    openFile(file);
    int id;
    vector<int> idInput;
    while(file>>id){
        idInput.push_back(id);
        file.ignore(9999,'\n');
    }
    vector<int> uniqueV;

//    sort(idInput.begin(), idInput.end());

    mergeSort(idInput, 0, idInput.size()-1);

    for (int i = 0; i < idInput.size(); i += 1){
        if (uniqueV.empty()){
            uniqueV.push_back(idInput[i]);
        }
        else {
            if(!binarySearch(uniqueV,0, uniqueV.size()-1, idInput[i])){
                uniqueV.push_back(idInput[i]);
            }
        }
    }

    ofstream outputFile;
    outputFile.open("output.txt");
    for (int i = 0; i < uniqueV.size(); i += 1){
        outputFile<<uniqueV[i]<<endl;
    }

    outputFile.close();
    file.close();
}
bool binarySearch(vector<int> v, int start, int end, int val){
    bool found = false;
    while(!found && (start<=end)){
        int middle = (end+start)/2;
        if (v[middle] == val){
            found = true;
        }
        else if (v[middle] < val){
            return binarySearch(v, middle+1, end, val);
        }
        else if (v[middle]>val){
            return binarySearch(v, start, middle-1, val);
        }
    }
    return found;
}
void mergeSort(vector<int>& v, int start, int end){
    int low = start;
    int high = end;
    if (low < high){
        int middle = (low+high)/2;
        mergeSort(v, start, middle);
        mergeSort(v, middle+1, high);
        merge(v, start,middle,end);
    }
}
void merge(vector<int>& v, int start, int middle, int end){
    vector<int> res;
    int iSize = (middle-start)+1;
    int jSize = end-middle;
    int L[iSize];
    int R[jSize];
    for (int i = 0; i < iSize; i += 1){
        L[i] = v[start+i];
    }
    for (int j = 0; j < jSize; j += 1){
        R[j] = v[middle+1+j];
    }

    int index = start;
    int i = 0;
    int j = 0;

    while(i < iSize && j < jSize){
        if(L[i] <= R[j]){
            v[index] = L[i];
            i += 1;
            index += 1;
        }
        else {
            v[index] = R[j];
            j += 1;
            index += 1;
        }
    }
    while(i< iSize){
        v[index] = L[i];
        i += 1;
        index += 1;
    }
    while (j< jSize){
        v[index] = R[j];
        j += 1;
        index += 1;
    }
}
void openFile(ifstream& file){
    cout<<"Enter name"<<endl;
    string name;
    cin>>name;
    file.open(name);
    while (!file){
        cout<<"Wrong, enter again"<<endl;
        cin>>name;
        file.clear();
        file.open(name);
    }
}