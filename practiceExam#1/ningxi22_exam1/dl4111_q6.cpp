#include <iostream>
using namespace std;

int main() {

    int totalSeqNum;

    cout<<"How many sequences do you wish to enter?"<<endl;
    cin>>totalSeqNum;

    cout<<"Please enter "<<totalSeqNum<<" lines, each with a sequence of positive integers."
        <<" For each sequence, separate the elements by a space, and end it by typing -1:"<<endl;

    int seqCounter = 1;
    int evensCount = 0;
    int oddsCount = 0;

    while (seqCounter <= totalSeqNum){
        cout<<"Sequence #"<<seqCounter<<": ";
        bool seenEndOfInput = false;
        int currentElement;
        int elementCount = 0;
        while (!seenEndOfInput){
            cin>>currentElement;
            if (currentElement == -1){
                seenEndOfInput = true;
            }
            else {
                elementCount += 1;
            }

        }
        if (elementCount%2 ==0){
            evensCount += 1;
        }
        else {
            oddsCount += 1;
        }

        seqCounter += 1;
    }

    cout<<"There were "<<evensCount<<" with even number of elements, and "
        <<oddsCount<<" with odd number of elements"<<endl;

    return 0;
}

