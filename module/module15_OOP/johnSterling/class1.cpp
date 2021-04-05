/*
	Example of simplest class.
	John Sterling
	CS1124
	Polytechnic University
*/
#include <string>
#include <iostream>
using namespace std;

// The class NothingHere is a valid class.  It doesn't have anything
// in it.

class NothingHere {
};	// Remember to put the semi-colon here or you will get strange errors.

int main() {
    NothingHere x;

    // Not much we can do with the NothingHere class,
    // except create an instance of one.
    // Hm, let's see, how big is our NothingHere?
    // Even an empty class like this takes up a single byte.
    // (Can you guess why?)
    cout << "sizeof(x) =  " << sizeof(x) << endl;
}
