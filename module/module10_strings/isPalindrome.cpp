#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void swap(char& v1, char& v2);
string reverse(const string& s);
string remove_punc(const string& s, const string& punc);
string make_lower(const string& s);
bool is_pal(const string& s);

int main() {

    string str;
    cout<<"Enter a candidate for palindrome test: "<<endl;
    cin>>str;
    if (is_pal(str)){
        cout<<"\""<<str<<"\" is a palindrome."<<endl;
    }
    else {
        cout<<"\""<<str<<"\" is not a palindrome."<<endl;
    }

    return 0;
}

void swap(char& v1, char& v2){
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

string reverse(const string& s){
    int start = 0;
    int end = s.length();
    string temp(s);

    while (start < end){
        end -= 1;
        swap(temp[start], temp[end]);
        start += 1;
    }
    return temp;
}

string make_lower(const string& s){
    string temp(s);
    for (int i = 0; i < s.length(); i += 1){
        temp[i] = tolower(s[i]);
    }
    return temp;
}

string remove_punc(const string& s, const string& punc){
    string no_punc;
    int s_length = s.length();
    int punc_length = punc.length();
    for (int i = 0; i < s_length; i += 1){
        string a_char = s.substr(i, 1);
        int location = punc.find(a_char, 0);
        if (location < 0 || location >= punc_length){
            no_punc = no_punc + a_char;
        }
    }
    return no_punc;
}

bool is_pal(const string& s){
    string punc(",;:.?!'\" ");
    string str(s);
    str = make_lower(str);
    string lower_str = remove_punc(str, punc);
    return (lower_str == reverse(lower_str));
}



