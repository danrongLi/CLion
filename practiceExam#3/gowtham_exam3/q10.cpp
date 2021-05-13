#include <iostream>

using namespace std;

class Exam{
public:
    Exam(){}
    virtual int getResults() = 0;
private:
};

class WrittenExam: public Exam{
public:
    WrittenExam(){}
    virtual int getResults(){
        return 1;
    }
private:
};

class PracticalExam: public Exam{
public:
    PracticalExam(){}
    virtual int getResults(){
        return -1;
    }
private:

};


int main(){

}