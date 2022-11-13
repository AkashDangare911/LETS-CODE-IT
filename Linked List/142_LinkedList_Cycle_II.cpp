/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

Do not modify the linked list.*/

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

    ListNode *findIntersection(ListNode *slow,ListNode *head){
        
        ListNode *entry = head;
        while(slow != entry)
        {
            slow = slow->next;
            entry = entry->next;
        }
        return entry;
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr)
            return nullptr;
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast )
                return findIntersection(slow,head);
        }
        
        return nullptr;
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
    
    fifth -> next = second;     // cycle is present

    ListNode *ans = obj.detectCycle(first);
    cout<<"Is Cycle present in Linked List at Node -> "<< ans->data <<endl;
    
    return 0;
}