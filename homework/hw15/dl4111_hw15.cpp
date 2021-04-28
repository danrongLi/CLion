#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

void openInputFile(ifstream& empFile, ifstream& payFile);

class Employee{
public:
    Employee(){id = 0; rate = 0.0; name = "No Name";hours = 0.0; totalPay = 0.0;}
    Employee(int newId, double newRate, string newName, double newHours):id(newId), rate(newRate),
                name(std::move(newName)), hours(newHours), totalPay(newRate*newHours){}

    void setId(int newId){id = newId;}
    void setRate(double newRate){rate = newRate;}
    void setName(string newName){name = std::move(newName);}
    void setHours(double newHours){hours = newHours;}
    void setTotalPay(){totalPay = hours*rate;}

    int getId() const {return id;}
    double getRate() const {return rate;}
    string getName() const {return name;}
    double getHours() const {return hours;}

    friend ostream& operator<<(ostream& outs, const Employee& emp);

private:
    int id;
    double rate;
    string name;
    double hours;
    double totalPay;
};
ostream& operator<<(ostream& outs, const Employee& emp){
    outs<<emp.name<<", $"<<emp.totalPay<<endl;
    return outs;
}

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
    void printList();
    Node<T>* getHead() const {return head;}

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
                return;

            }
            else {
                currentNode = currentNode -> next;
            }
        }
        if (currentNode->next->data == tobeRemoved){
            currentNode->next = nullptr;
            return;
        }
        cout<<"Node Not Found"<<endl;
    }
}

template <class T>
int LList<T>::size() {
    int count = 0;
    if (head == nullptr){
        return count;
    }
    Node<T>* currentNode = head;
    while (currentNode->next != nullptr){
        count += 1;
        currentNode = currentNode->next;
    }
    return count;
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
template <class T>
void LList<T>::printList() {
    Node<T>* currentNode = head;
    if (currentNode == nullptr){
        cout<<"empty list!"<<endl;
    }
    else{
        while (currentNode!= nullptr){
            cout<<*(currentNode->data)<<endl;
            currentNode = currentNode->next;
        }
    }
}

int main(){
    ifstream empFile, payFile;
    openInputFile(empFile, payFile);

    LList<Employee*> employeeList;
    int inputId;
    double inputRate;
    string inputName;
    while (empFile>>inputId){
        empFile>>inputRate;
        empFile.ignore(9999,' ');
        getline(empFile,inputName);
        auto* tempEmp = new Employee();
        tempEmp->setId(inputId);
        tempEmp->setRate(inputRate);
        tempEmp->setName(inputName);
        employeeList.addAtBack(tempEmp);
    }
    double inputHours;
    while(payFile>>inputId>>inputHours){
        Node<Employee*>* currentEmp = employeeList.getHead();
        while (currentEmp!= nullptr){
            if (currentEmp->getData()->getId() == inputId){
                currentEmp->getData()->setHours(inputHours+currentEmp->getData()->getHours());
                currentEmp->getData()->setTotalPay();
                currentEmp = currentEmp->getNext();
            }
            else {
                currentEmp = currentEmp->getNext();
            }
        }
    }



    employeeList.printList();

    empFile.close();
    payFile.close();

    return 0;
}


void openInputFile(ifstream& empFile, ifstream& payFile){
    string empName;
    string payName;

    cout<<"Enter your employment file name with extension"<<endl;
    cin>>empName;
    empFile.open(empName);
    while (!empFile){
        cout<<"Inaccurate employment file name"<<endl;
        cout<<"Enter again"<<endl;
        cin>>empName;
        empFile.clear();
        empFile.open(empName);
    }

    cout<<"Enter your payroll file name with extension"<<endl;
    cin>>payName;
    payFile.open(payName);
    while(!payFile){
        cout<<"Inaccurate payroll file name"<<endl;
        cout<<"Enter again"<<endl;
        cin>>payName;
        payFile.clear();
        payFile.open(payName);
    }
}