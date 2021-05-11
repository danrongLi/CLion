#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void openFile(ifstream& file1, ifstream& file2);

int main(){

    ifstream file1, file2;
    openFile(file1, file2);
    int sum = 0;
    string num;
    while (file1>>num){
        cout<<num<<" ";
    }
    while(file2>>num){
        cout<<num<<" ";
    }
    cout<<sum<<endl;


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