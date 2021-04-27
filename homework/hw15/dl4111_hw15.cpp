#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

class Employee{
public:
    Employee(){id = 0; rate = 0.0; name = "No Name";}
    Employee(int newId, double newRate, string newName):id(newId), rate(newRate), name(newName){}

    void setId(int newId){id = newId;}
    void setRate(double newRate){rate = newRate;}
    void setName(string newName){name = newName;}

    int getId() const {return id;}
    double getRate() const {return rate;}
    string getName() const {return name;}

private:
    int id;
    double rate;
    string name;
};

template <class T>
class LList;

template <class T>
class Node{
public:
    friend class LList<T>;
    Node(){data = T(); next = nullptr; prev = nullptr;}
    Node(const T& newData, Node<T>* newNext, Node<T>* newPrev):data(newData), next(newNext), prev(newPrev) {}
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class LList{
public:
    LList(){head = new Node<T>(); tail = new Node<T>(); head->next = tail; tail->prev = head;}
    LList(const LList<T>& rhs){}
    ~LList();

    void push_back(const T& data){tail->prev = new Node<T>(data, tail, tail->prev); tail->prev->prev->next = tail->prev;}

private:
    Node<T>* head;
    Node<T>* tail;
};