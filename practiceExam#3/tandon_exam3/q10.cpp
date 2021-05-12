#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
};

ListNode* reverse_linked_list(ListNode* head){
    // Reverse the linked list and return the new head after reversing
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while(curr != nullptr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

bool is_target_in_list(ListNode* head, int target){
    // Check if the linked list contains the target
    ListNode* currentNode = head;
    while (currentNode != nullptr){
        if (target == currentNode->val){
            return true;
        }
        else {
            currentNode = currentNode->next;
        }
    }
    return false;

}

int find_max(ListNode* head){
    // Find the largest value in the node
    ListNode* currentNode = head;
    int currentMax = currentNode->val;
    while (currentNode != nullptr){
        if (currentNode->val > currentMax){
            currentMax = currentNode->val;
            currentNode = currentNode->next;
        }
        else {
            currentNode = currentNode->next;
        }
    }
    return currentMax;
}
