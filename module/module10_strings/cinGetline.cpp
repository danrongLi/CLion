#include <iostream>
#include <string>
using namespace std;

void new_line();
int main() {

    int n;
    string line;
    cin>>n;

    cout<<"n: "<<n<<endl;

    new_line();
    getline(cin, line);

    cout<<"line: "<<line<<endl;

    return 0;
}

void new_line(){
    char nextChar;
    do{
        cin.get(nextChar);
    }while (nextChar != '\n');
}

