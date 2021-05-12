#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void openFile(ifstream& file);

int main() {

    ifstream file;
    openFile(file);
    vector<string> vectorString;
    vector<int> vectorCount;

    string current;
    while(file>>current){
        vectorString.push_back(current);
    }

    int count[vectorString.size()];
    for (int i = 0; i < vectorString.size(); i += 1){
        count[i] = 0;
    }

    bool placementHappened;
    int placement = 1;
    int currentIndex = 0;
    vector<string> uniqueV;
    do{
        placementHappened = false;
        bool pushed = false;
        int num = 0;
        for (int i = 0; i < vectorString.size(); i += 1){
            if (vectorString[i] == vectorString[currentIndex]){
                if (count[i] == 0){
                    count[i] = placement;
                    placementHappened = true;
                    num += 1;
                    if (!pushed){
                        uniqueV.push_back(vectorString[currentIndex]);
                        pushed = true;
                    }

                }
            }
        }
        if(placementHappened){
            placement += 1;
            currentIndex += 1;
            vectorCount.push_back(num);
        }

    }while(placementHappened);

    for (int i = 0; i < uniqueV.size(); i += 1){
        cout<<uniqueV[i]<<" "<<vectorCount[i]<<endl;
    }


    file.close();

    return 0;
}

void openFile(ifstream& file){
    string name;
    cout<<"Enter file name"<<endl;
    cin>>name;
    file.open(name);
    while(!file){
        cout<<"Wrong name, enter again"<<endl;
        cin>>name;
        file.clear();
        file.open(name);
    }
}