#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>

using namespace std;

class Person {
    int id;
    string name;
public:
    Person(int newid = 0, string newname = "") :name(newname), id(newid) {}
    int getID() const { return id; }
    string getName() const { return name; }
    void setID(int newID) { id = newID; }
    void setName(string newName) { name = newName; }
};
istream& operator>>(istream& ins, Person& rhs) {
    //     ins    >>tempName //step 2
    //(ins>>tempID) //step 1
    // ins>>tempID>>tempName;
    int tempID;
    string tempName;
    ins >> tempID;
    ins >> tempName;
    rhs.setID(tempID);
    rhs.setName(tempName);
    return ins;
}




void openInputFile(ifstream& inFile) {
    string filename;
    cout << "What file name: ";
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "BAD FILENAME!"<<endl;
        cout << "What file name: ";
        cin >> filename;
        inFile.clear(); //may not be necessary in newer versions of C++
        inFile.open(filename);
    }
}

const int MAX_NAMES = 10;

int main() {
    list<Person> vp;
    ifstream inFile;
    openInputFile(inFile);
    Person temp;

    while (inFile >> temp && (vp.size() <MAX_NAMES)) {
        /*temp.setID(tempID);
        temp.setName(tempName);*/

        vp.push_back(temp);
    }
/*	Person temp;
	temp.setID(1);
	temp.setName("Johnny");
	vp.push_back(temp);

	temp.setID(2);
	temp.setName("Sheila");
	vp.push_back(temp);
*/
    cout << "First way:" << endl;
    for (Person p : vp) { //for (int i=0; i<vp.size(); i++)
        cout << p.getName() << endl;
    }

    /*cout << endl << endl << "Second way:" << endl;
    for (int i = 0; i < vp.size(); i++)
        cout << vp[i].getName() << endl;*/
    cout << endl << endl << "Second way:" << endl;
    for (list <Person>::iterator i = vp.begin(); i != vp.end(); i++)
        cout << i->getName() << endl; //(*i).getName()
}