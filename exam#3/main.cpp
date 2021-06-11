#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
class LListNode{
public:
    void fixTheList(LListNode<T>* first){
        int count = 1;
        LListNode* current = first;
        while (current != nullptr){
            if (count%2 == 0){
                LListNode* temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                count += 1;
                current = current ->next;
            }
            else{
                current = current->next;
                count += 1;
            }
        }
    }
private:
    LListNode* prev;
    LListNode* next;
};







vector<double> getBusLineInfo(string busLine);
bool bussesTooClose(string busLine);
double findAbs(double num);
int main() {
    return 0;
}
vector<double> getBusLineInfo(string busLine){
}
bool bussesTooClose(string busLine){
    vector<double> givenV = getBusLineInfo(busLine);
    sort(givenV.begin(), givenV.end());

    bool foundClose = false;
    int index = 1;
    while (!foundClose && index < givenV.size()){
        if (givenV[index]-givenV[index-1] < 1){
            foundClose = true;
        }
        else {
            index += 1;
        }
    }
    if (foundClose){
        return true;
    }
    else {
        return false;
    }
}











bool bussesTooClose2(string busLine){
    vector<double> givenV = getBusLineInfo(busLine);
    bool foundClose = false;
    int index = 0;
    while (index < givenV.size()-1 && !foundClose){
        index = 0;
        int i = index + 1;
        while(!foundClose && i < givenV.size()){
            //findAbs returns the absolute value
            if (findAbs(givenV[i]-givenV[index]) < 1){
                foundClose = true;
            }
            else {
                i += 1;
            }
        }
        index += 1;
    }
    if (foundClose){
        return true;
    }
    else {
        return false;
    }
}
double findAbs(double num){
    if (num < 0){
        num  = 0-num;
        return num;
    }
    else {
        return num;
    }
}
