#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

class Song{
public:
    Song(string songArtist, string songTitle);
    string getSongArtist()const {return _songArtist;}
    string getSongTitle()const {return _songTitle;}

    friend ostream&operator <<(ostream& outs, const Song& song);
private:
    string _songArtist;
    string _songTitle;
};

Song::Song(string songArtist, string songTitle) {
    _songArtist = songArtist;
    _songTitle = songTitle;
}

ostream& operator<<(ostream& outs, const Song& song){
    outs<<"Artist: "<<song._songArtist<<endl;
    outs<<"Title: "<<song._songTitle<<endl;
    return outs;
};

template <class T>
class LinkedList;

template <class T>
class Node{
public:
    friend class LinkedList<T>;
    friend ostream& operator<<(ostream& outs, const Node<T>& node);
    Node();
    Node(T node);
    T getData() const {return data;}
    Node<T>* getNext() const {return next;}
    Node<T>* getPrev() const {return prev;}
private:
    Node<T>* next;
    Node<T>* prev;
    T data;
};

template <class T>
ostream& operator<<(ostream& outs, const Node<T>& node){
    outs<<node.data;
    return outs;
}

template <class T>
Node<T>::Node() {
    data = nullptr;
    next = 0;
    prev = 0;
}

template <class T>
Node<T>::Node(T node){
    data = node;
    next = 0;
    prev = 0;
}

template<class T>
class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    void addAtFront(T node);
    void addAtBack(T node);
    void addAfterNode(T oldNode, T nodeToInsert);
    void removeNode(T node);
    void printList();
    int size();

    template <class TT>
    friend ostream& operator<<(ostream& outs, const LinkedList<TT>& obj);
private:
    Node<T>* head;

};

template <class TT>
ostream& operator<<(ostream& outs, const LinkedList<TT>& obj){
    Node<TT>* temp = obj.head;
    while (temp != nullptr){
        outs<<*temp->getData()<<endl;
        temp = temp->getNext();
    }
    cout<<endl;
    return outs;
}

template <class T>
LinkedList<T>::LinkedList() {
    head = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* node = head;
    Node<T>* tempNode;
    while (node != nullptr){
        tempNode = node;
        node = node -> next;
        delete tempNode;
    }
}

template <class T>
void LinkedList<T>::addAtFront(T node) {
    Node<T>* newNode = new Node<T>();
    newNode->data = node;
    if (head == nullptr){
        head = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

template <class T>
void LinkedList<T>::addAtBack(T node) {
    Node<T>* newNode = new Node<T>();
    newNode->data = node;
    if (head == nullptr){
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

template <class T>
void LinkedList<T>::addAfterNode(T oldNode, T nodeToInsert) {
    Node<T>* newNode = new Node<T>();
    newNode->data = nodeToInsert;
    Node<T>* oNode = new Node<T>();
    oNode->data = oldNode;

    if (head == nullptr){
        head = newNode;
    }
    else {
        Node<T>* temp = head;
        Node<T>* temp2;
        while(temp->data != oNode->data){
            if (temp->next == nullptr){
                cout<<"Node Not Found In List"<<endl;
                break;
            }
            else {
                temp = temp->next;
            }
        }
        temp2 = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = temp2;
        temp2->prev = newNode;
    }
}

template <class T>
void LinkedList<T>::removeNode(T node) {
    Node<T>* temp;
    Node<T>* temp2;
    if (head == nullptr){
        cout<<"the list is empty";
        return;
    }
    else if (head->data == node){
        temp = head;
        if (head->next != nullptr){
            head = head->next;
            head->prev = nullptr;
            delete temp;
            temp = nullptr;
            return;
        }
        else {
            delete head;
            head = nullptr;
            delete temp;
            temp = nullptr;
            return;
        }
    }
    temp2 = head;
    while(temp2->next->next != nullptr){
        if (temp2->next->data == node){
            temp = temp2->next;
            temp2->next = temp->next;
            temp->next->prev = temp2;
            delete temp;
            temp = nullptr;
            return;
        }
        temp2 = temp2->next;
    }
    if (temp2->next->data == node){
        temp = temp2->next;
        delete temp;
        temp = nullptr;
        temp2->next = nullptr;
        return;
    }
    cout<<"element not found"<<endl;
}

template <class T>
int LinkedList<T>::size() {
    if (head == nullptr){
        return 0;
    }
    Node<T>* temp = head;
    int count = 0;
    while (temp != nullptr){
        count += 1;
        temp = temp->next;
    }
    return count;
}

template <class T>
void LinkedList<T>::printList() {
    Node<T>* temp = head;
    if (temp == nullptr){
        cout<<"list is empty"<<endl;
        return;
    }
    if (temp->next == nullptr){
        cout<<temp->data<<endl;
        return;
    }
    else {
        while (temp != nullptr){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
    cout<<"Print List"<<endl;
}

int main(){
    Song *song = new Song("Queen", "We will rock you");
    Song *song2 = new Song("Queen", "I want it all");
    Song *song3 = new Song("Queen", "We are the champions");

    LinkedList<Song*> myList;

    myList.addAtFront(song);
    myList.addAtBack(song2);
    myList.addAfterNode(song, song3);
    cout<<myList<<endl;

    myList.removeNode(song3);
    cout<<myList<<endl;

    myList.removeNode(song2);
    cout<<myList<<endl;
    cout<<myList.size()<<endl;


    return 0;
}