#include <fstream>
#include <iostream>
#include <string>
#include <list>

using namespace std;

void openFile(ifstream& file1, ifstream& file2);

int main(){

    ifstream file1, file2;
    openFile(file1, file2);
    list<int> list1;
    list<int> list2;

    int sum = 0;
    string num;
    while (getline(file1, num)){
        for(auto numIndi:num){
            int n = numIndi-'0';
            list1.push_back(n);
        }
    }
    while(getline(file2, num)){
        for(auto numIndi:num){
            int n = numIndi-'0';
            cout<<n;
            list2.push_back(n);
        }
        cout<<endl;
    }


    return 0;
}

void openFile(ifstream& file1, ifstream& file2){
    string name1;
    string name2;

    cout<<"Enter file names"<<endl;
    cin>>name1>>name2;

    file1.open(name1);
    file2.open(name2);
    while (!file1 || !file2){
        cout<<"Wrong name, enter again"<<endl;
        cin>>name1>>name2;
        file1.clear();
        file2.clear();
        file1.open(name1);
        file2.open(name2);
    }
}