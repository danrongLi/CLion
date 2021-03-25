#include <iostream>
using namespace std;

bool isPalindrome(int seq[], int seqSize);

int main() {

    int seq[10] = {4,3,12,100,12,3,4};
    int seqSize = 7;
    bool isPal = isPalindrome(seq, seqSize);

    if(isPal){
        cout<<"ye"<<endl;
    }
    else{
        cout<<"noo"<<endl;
    }

    return 0;
}
bool isPalindrome(int seq[], int seqSize){
    bool previousResult;

    if(seqSize == 2){
        if (seq[0] == seq[1]){
            return true;
        }
        else{
            return false;
        }
    }
    else if (seqSize == 3){
        if (seq[0] == seq[seqSize-1]){
            return true;
        }
        else {
            return false;
        }
    }

    else {
        previousResult = isPalindrome(seq+1, seqSize-2);
        if (!previousResult){
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