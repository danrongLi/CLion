#include <iostream>
using namespace std;

void printAsc(int start, int end);
int main() {

    printAsc(1,5);

    return 0;
}
void printAsc(int start, int end){
    if (start == end){
        cout<<"base situation"<<endl;
        cout<<start<<endl;
    }
    else {
//        int mid = (start+end)/2;
//        printAsc(start,mid);
//        printAsc(mid+1,end);
        cout<<"start looping "<<start<<" "<<end<<endl;
        cout<<start<<endl;
        printAsc(start+1, end);
        cout<<"end looping "<<start<<" "<<end<<endl;
        cout<<start<<endl;
    }
}