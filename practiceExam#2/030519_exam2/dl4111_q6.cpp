#include <iostream>
using namespace std;

bool is2dupSequence(int seq[], int seqSize);

int main() {
    int seq[10] = {3,3,14,14,2,2,};
    int seqSize = 6;
    bool is2dup = is2dupSequence(seq, seqSize);
    if (is2dup){
        cout<<"ye"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}

bool is2dupSequence(int seq[], int seqSize){

    bool previousResult;

    if (seqSize == 2){
        if (seq[0] == seq[1]){
            return true;
        }
        else {
            return false;
        }
    }

    else {
        previousResult = is2dupSequence(seq+2, seqSize-2);
        if (!previousResult){
            return false;
        }
        else {
            if (seq[0] == seq[1]){
                return true;
            }
            else {
                return false;
            }
        }
    }

}