/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

Return true if there is a cycle in the linked list. Otherwise, return false.*/

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
    ListNode(ListNode *n , int d){
        next = n;
        data = d;
    }

    bool hasCycle(ListNode *head) {
        
        if(head == nullptr)
            return false;
        ListNode * fast = head;
        
        while(fast->next && fast ->next -> next)
        {
            head = head -> next;
            fast = fast -> next -> next;
            
            if(head == fast )
                return true;
        }
        return false;
    }
    void print(ListNode *head){
        int i = 0;
        while(head){
            cout<<head->data<<" ";
            head = head ->next;
            if(i++ > 100)
                break;
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
    
    // fifth -> next = second;     // cycle is present

    cout<<"Is Cycle present in Linked List -> "<<obj.hasCycle(first)<<endl;
    
    obj.print(first);
    return 0;
}