#include <iostream>

using namespace std;

template <class T>
class LListNode{
public:
    LListNode(LListNode<T>* newN = nullptr){next = newN;}

    LListNode<T>* getConcat(LListNode<T>* firstHead, LListNode<T>* secondHead){
        LListNode<T>* result;
        while(firstHead != nullptr){
            if (result == nullptr){
                result = firstHead;
                firstHead = firstHead ->next;
            }
            else {
                result->next = firstHead;
                result = result->next;
                firstHead = firstHead -> next;
            }
        }
        while(secondHead != nullptr){
            if (result == nullptr){
                result = secondHead;
                secondHead = secondHead ->next;
            }
            else {
                result->next = secondHead;
                result = result->next;
                secondHead = secondHead -> next;
            }
        }
        return result;
    }
private:
    LListNode* next;
};


int main() {

    return 0;
}
