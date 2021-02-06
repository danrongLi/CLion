#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ONE = 1;
const int HUNDRED = 100;
const int FIVE = 5;

int main() {

    int myNumber;
    int numberGuessLeft = FIVE;
    int userGuess;
    int lowerBound = ONE;
    int upperBound = HUNDRED;

    srand(time(0));

    myNumber = (rand() % 100) + 1;

    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;
    while (numberGuessLeft > 0){
        cout<<"Range: ";
        cout<<"["<<lowerBound<<", "<<upperBound<<"], Number of guesses left: "<<numberGuessLeft<<endl;
        cout<<"Your guess: ";
        cin>>userGuess;
        if ((numberGuessLeft == 1) && (userGuess != myNumber)){
            cout<<"Out of guesses! My number is "<<myNumber<<endl;
            numberGuessLeft -= 1;
        }
        else if (userGuess == myNumber){
            cout<<"Congrats! You guessed my number in "<<FIVE-numberGuessLeft+ONE<<" guesses."<<endl;
            numberGuessLeft = 0;
        }
        else if (userGuess < myNumber){
            cout<<"Wrong! My number is bigger.\n"<<endl;
            numberGuessLeft -= 1;
            if (userGuess > lowerBound){
                lowerBound = userGuess + 1;
            }
        }
        else if (userGuess > myNumber){
            cout<<"Wrong! My number is smaller.\n"<<endl;
            numberGuessLeft -= 1;
            if (userGuess < upperBound) {
                upperBound = userGuess - 1;
            }
        }
    }

    return 0;
}
