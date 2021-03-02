#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
int main() {

    string wordEnter;
    cout<<"Please enter a word: ";
    cin>>wordEnter;

    if (isPalindrome(wordEnter)){
        cout<<wordEnter<<" is a palindrome"<<endl;
    }
    else {
        cout<<wordEnter<<" is not a palindrome"<<endl;
    }

    return 0;

}
bool isPalindrome(string str){
    int frontCount = 0;
    int endCount = str.length() - 1;
    bool isPal = true;
    if ((str.length() % 2 == 0) && (isPal)){
        while ((endCount - frontCount) >= 1){
            if (str[endCount] != str[frontCount]){
                isPal = false;
            }
            endCount -= 1;
            frontCount += 1;
        }
    }
    else {
        while (((endCount - frontCount) >= 2) && (isPal)){
            if (str[endCount] != str[frontCount]){
                isPal = false;
            }
            endCount -= 1;
            frontCount += 1;
        }
    }
    return isPal;
}