#include <iostream>
using namespace std;

bool isPalindrome(int seq[], int seqSize);
// we assume the size is always even

int main() {

    int seqSize = 8;
    int seq[10] = {3,12,4,2,2,4,12,3};
//
//    int seqSize = 2;
//    int seq[10] = {3,3};

    bool ifPal = isPalindrome(seq, seqSize);

    if(ifPal){
        cout<<"It is Palindrome"<<endl;
    }
    else {
        cout<<"It's not Palindrome"<<endl;
    }

    return 0;
}

bool isPalindrome(int seq[], int seqSize){

    bool previousRes;

    if (seqSize == 2){
        if (seq[0] == seq[1]){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        previousRes = isPalindrome(seq+1, seqSize-2);
        if(!previousRes){
            return false;
        }
        else {
            if (seq[0] == seq[seqSize-1]){
                return true;
            }
            else {
                return false;
            }
        }
    }


}