/*There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the tail node */
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    ListNode *next ;
    int data ;

    ListNode(){
        next = nullptr;
        int data = 0;
    }
    ListNode(int d){
        next = nullptr;
        data = d;
    }
    ListNode(ListNode * n , int d){
        next = n;
        data = d;
    }
    void deleteNode(ListNode* node) {
         node->data=node->next->data;       // copy data of next node
        node->next=node->next->next;        // delete the next node
    }

    void print(ListNode *head){
        while(head){
            cout<<head->data<<" ";
            head = head ->next;
        }
        cout<<endl;
    }
};

int main()
{
    ListNode obj;

    ListNode *first = new ListNode(1);      
    ListNode *second = new ListNode(2);     first ->next = second;
    ListNode *third = new ListNode(3);      second ->next = third;
    ListNode *fourth = new ListNode(4);     third ->next = fourth;
    ListNode *fifth = new ListNode(5);      fourth ->next = fifth;
    fifth->next = NULL;
    
    obj.print(first);
    obj.deleteNode(second);
    obj.print(first);
    return 0;
}
