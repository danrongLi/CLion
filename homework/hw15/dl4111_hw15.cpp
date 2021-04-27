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
    Node(){data = nullptr; next = nullptr; prev = nullptr;}
    explicit Node(T newData){data = newData; next = nullptr; prev = nullptr;}

    T getData() const {return data;}
    Node<T>* getNext() const {return next;}
    Node<T>* getPrev() const {return prev;}
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class LList{
public:
    LList(){head = nullptr;}
    ~LList();

    void addAtFront(T newNode);
    void addAtBack(T newNode);
    void addAfterNode(T newNode, T oldNode);
    void removeNode(T tobeRemoved);
    int size();

    template <class TT>
    friend ostream& operator << (ostream& outs, const LList<TT>& obj);

private:
    Node<T>* head;
};

template <class T>
void LList<T>::addAtFront(T newNode) {
    auto* nNode = new Node<T>(newNode);
    if (head == nullptr){
        head = nNode;
    }
    else {
        head->prev = nNode;
        nNode->next = head;
        head = nNode;
    }
}

template <class T>
void LList<T>::addAtBack(T newNode) {
    auto* nNode = new Node<T>(newNode);
    if (head == nullptr){
        head = nNode;
    }
    else {
        Node<T>* currentNode = head;
        while (currentNode->next != nullptr){
            currentNode = currentNode -> next;
        }
        currentNode->next = nNode;
        nNode->prev = currentNode;
    }
}

template <class T>
void LList<T>::addAfterNode(T newNode, T oldNode) {
    auto* nNode = new Node<T>(newNode);
    auto* oNode = new Node<T>(oldNode);
    if (head == nullptr){
        head = nNode;
    }
    else {
        Node<T>* currentNode = head;
        Node<T>* tempNode;
        bool notFound = false;
        while (currentNode->data != oNode->data && !notFound){
            if (currentNode->next == nullptr){
                cout<<"node not found!"<<endl;
                notFound = true;
            }
            else {
                currentNode = currentNode->next;
            }
        }
        tempNode = currentNode->next;
        currentNode->next = nNode;
        nNode->prev = currentNode;
        nNode->next = tempNode;
        tempNode->prev = nNode;
    }
}

template <class T>
void LList<T>::removeNode(T tobeRemoved) {
    if (head == nullptr){
        cout<<"The list is empty"<<endl;
        return;
    }
    else if (head->data == tobeRemoved){
        // trying to remove the head node
        if (head->next == nullptr){
            delete head;
            head = nullptr;
        }
        else if (head->next != nullptr){
            head = head->next;
            head->prev = nullptr;
        }
    }
    else {
        Node<T>* currentNode = head;
        while (currentNode->next->next != nullptr){
            if (currentNode->next->data == tobeRemoved){
                currentNode->next = tobeRemoved->next;
                tobeRemoved->next->prev = currentNode;

            }
            else {
                currentNode = currentNode -> next;
            }
        }
        if (currentNode->next->data == tobeRemoved){
            currentNode->next = nullptr;

        }
    }
}

template <class T>
LList<T>::~LList(){
    Node<T>* currentNode = head;
    Node<T>* tempNode;
    while(currentNode != nullptr){
        tempNode = currentNode;
        currentNode = currentNode->next;
        delete tempNode;
        tempNode = nullptr;
    }
}
