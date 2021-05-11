#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sorting{
public:
    virtual void sort(vector<int> data) = 0;
    virtual string worst_case_runtime() = 0;

private:
    vector<int> data;
};

class InsertionSort: public Sorting{
public:
    virtual void sort(vector<int> data);
    virtual string worst_case_runtime(){return "O(n^2)";}
private:

};

class QuickSort: public Sorting{
public:
    virtual void sort(vector<int> data);
    virtual string worst_case_runtime(){return "O(n^2)";}
private:
};

class MergeSort: public Sorting{
public:
    virtual void sort(vector<int> data);
    virtual string worst_case_runtime(){return "O(n*(log(n)))";}
private:
};

void InsertionSort::sort(vector<int> data) {

}

void QuickSort::sort(vector<int> data) {

}

void MergeSort::sort(vector<int> data) {

}


int main(){
    return 0;
}