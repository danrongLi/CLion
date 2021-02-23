#include <iostream>
#include <string>
using namespace std;

int main() {

    string word1, word2, word3;
    cout<<"Please enter 3 words separated by a space:"<<endl;
    cin>>word1>>word2>>word3;

    if ((word1 <= word2) && (word1 <= word3)){
        cout<<word1<<endl;
    }
    else if ((word2 <= word1) && (word2 <= word3)){
        cout<<word2<<endl;
    }
    else {
        cout<<word3<<endl;
    }

    return 0;
}

