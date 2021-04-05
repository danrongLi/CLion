/*
	textVectorOfPointersToStructs.cpp
	1) read a file of integers into a vector of struct pointers
	   We will have to create an object on the heap for each
	   item in the file.
	2) display the values in the vector
	3) free up the heap space that we used

	Note similarity to textVectorBasics.cpp
*/

#include <iostream>	// cout, cerr, endl
#include <fstream>	// ifstream
#include <vector>	// vector
using namespace std;

struct HiImAStruct {
    int imAnInt;
};  // Remember the semi-colon.  I forgot it.  Again.

int main() {
    cout << "Program: textVectorOfPointersToStructs.cpp\n\n";

    // Open the data file
    ifstream ifs("integers.txt");
    if (!ifs) {
        cerr << "Couldn't open 'intergers.txt'\n";
        exit(1);
    }

    // Create a vector to put the data into.
    // Note that it is a vector of pointers to our struct.
    // The vector is initially empty.
    vector<HiImAStruct*> alfred;

    int x;  // Temporary variable to read the data into
    // Usual loop for reading all the items from a file
    while (ifs >> x) {
        // Create an instance of our struct on the heap
        HiImAStruct* p = new HiImAStruct;
        // Put the data that we read into the new object
        p->imAnInt = x;
        // Push the ADDRESS of the new object onto the end of the vector
        alfred.push_back(p);
    }

    // Loop over the vector printing out the values.
    for (size_t i = 0; i < alfred.size(); ++i)
        // Remember that we're storing pointers in the vector
        // so you need the arrow
        cout << alfred[i]->imAnInt << ' ';
    cout << endl;

    // If we allocate dynamic memory, then we should remember
    // to free it up.  Each element in the vector points to
    // an object that we created with new, so we should free
    // each of them up with delete.
    for (size_t i = 0; i < alfred.size(); ++i)
        delete alfred[i];

    // How many items are int the vector now?  You should check...

}