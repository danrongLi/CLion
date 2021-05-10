#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

void openFile(ifstream& empFile, ifstream& payFile);

template <class T>
void mySwap(T& a, T& b);

class Employee{
public:
    explicit Employee(string newName = " ", int newId = 0, double newRate = 0.0, int newHours = 0, double newPayment = 0.0){
        name = std::move(newName); id = newId; payRate = newRate; hours = newHours; payment = payRate*hours;
    }
    int getId() const {return id;}
    string getName() const {return name;}
    double getPayRate() const {return payRate;}
    double getPayment() const {return payment;}

    void addHours(int addition){hours += addition;}
    void setPayment(){payment = hours*payRate;}
    friend istream& operator>>(istream& ins, Employee& inputEmployee);
    friend ostream& operator<<(ostream& outs, const Employee& inputEmployee);

private:
    string name;
    int id;
    double payRate;
    int hours;
    double payment;
};

istream& operator>>(istream& ins, Employee& inputEmployee){
    ins>>inputEmployee.id>>inputEmployee.payRate;
    ins.ignore(9999,' ');
    getline(ins, inputEmployee.name);
    return ins;
}
ostream& operator<<(ostream& outs, const Employee& inputEmployee){
    outs<<inputEmployee.name<<", $"<<inputEmployee.payment;
    return outs;
}

template <class T>
class LList;

template <class T>
class Node{
public:
    explicit Node(T newData = T(), Node<T>* newNext = nullptr, Node<T>* newPrev = nullptr){data = newData; next = newNext; prev = newPrev;}

    T getData() const {return data;}
    Node<T>* getNext() const {return next;}
    Node<T>* getPrev() const {return prev;}

    void setNext(Node<T>* newNext){next = newNext;}
    void setPrev(Node<T>* newPrev){prev = newPrev;}
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class LList{
public:
    explicit LList(Node<T>* newHead = nullptr){head = newHead;}
    ~LList();
    Node<T>* getHead() const {return head;}
    void push_back(T newNode);
    int size();
    void print();
private:
    Node<T>* head;
};
template <class T>
void LList<T>::print() {
    if (head== nullptr){
        cout<<"Empty List"<<endl;
    }
    else {
        Node<T>* current = head;
        while(current!= nullptr){
            cout<<*(current->getData())<<endl;
            current = current->getNext();
        }
    }
}

template <class T>
int LList<T>::size(){
    int count;
    if (head == nullptr){
        count = 0;
    }
    else {
        Node<T>* current = head;
        count = 1;
        while (current->getNext() != nullptr){
            count += 1;
            current = current->getNext();
        }
    }
    return count;
}

template <class T>
void LList<T>::push_back(T newNode) {
    auto* nNode = new Node<T>(newNode);
    if (head == nullptr){
        head = nNode;
    }
    else {
        Node<T>* current = head;
        while (current->getNext() != nullptr){
            current = current->getNext();
        }
        current->setNext(nNode);
        nNode->setPrev(current);
    }
}

template <class T>
LList<T>::~LList<T>() {
    Node<T>* current = getHead();
    Node<T>* next;
    while (current != nullptr){
        next = current->getNext();
        delete current;
        current = next;
    }
}

int main(){
    ifstream empFile;
    ifstream payFile;
    openFile(empFile,payFile);

    LList<Employee*> employeeList;
    Employee newEmp = Employee();

    while (empFile>>newEmp){
        auto* tempEmp = new Employee(newEmp.getName(), newEmp.getId(), newEmp.getPayRate());
        employeeList.push_back(tempEmp);
    }

    int id;
    int hours;
    while(payFile>>id>>hours){
        Node<Employee*>* currentNode = employeeList.getHead();
        while (currentNode!= nullptr){
            if (id == currentNode->getData()->getId()){
                currentNode->getData()->addHours(hours);
                currentNode->getData()->setPayment();
                currentNode = currentNode->getNext();
            }
            else {
                currentNode->getData()->setPayment();
                currentNode = currentNode->getNext();
            }
        }
    }

    bool swapHappened;

    do {
        swapHappened = false;
        Node<Employee*>* current = employeeList.getHead();
        while (current->getNext()!= nullptr){

            if (current->getData()->getPayment() < current->getNext()->getData()->getPayment()){
                mySwap(*current->getData(), *current->getNext()->getData());
                swapHappened = true;
            }
            current = current->getNext();
        }

    }while (swapHappened);


    employeeList.print();

    empFile.close();
    payFile.close();

}

void openFile(ifstream& empFile, ifstream& payFile){
    string empFileName;
    string payFileName;

    cout<<"Enter employee file name"<<endl;
    cin>>empFileName;

    empFile.open(empFileName);
    while (!empFile){
        cout<<"Wrong name, enter again"<<endl;
        empFile.clear();
        empFile.open(empFileName);
    }

    cout<<"Enter payroll file name"<<endl;
    cin>>payFileName;

    payFile.open(payFileName);
    while(!payFile){
        cout<<"Wrong name, enter again"<<endl;
        payFile.clear();
        payFile.open(payFileName);
    }
}

template <class T>
void mySwap(T& a, T& b){
    T t = a;
    a = b;
    b = t;
}