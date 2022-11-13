/*You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.*/

#include<bits/stdc++.h>
using namespace std;

//  981 ms with 99.09% faster 
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
    // my solution
    ListNode* myDeleteMiddle(ListNode* head) {
        
        ListNode *temp = head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp = temp -> next;
        }
        if(count==1){
            head =nullptr;
            return head;
        }   
        
        count = count/2 -1;
        temp = head;

        while(count){
            temp = temp ->next;
            count--;
        }
        ListNode * t = temp -> next;
        temp -> next = t -> next;
        t ->next = nullptr;
        
        return head;
    }
    // better approach
   ListNode* deleteMiddle(ListNode* head) {
    
        if(head==NULL || head->next==NULL) return NULL;       
        
        ListNode *prev=NULL, * slow=head, * fast=head;       
        
        // get the middle element   
        while(fast!=NULL and fast->next!=NULL){                  
            prev=slow;            //prev is used to store the previous node of middle                      
            slow=slow->next;                               
            fast=fast->next->next;                         
        }
        
        prev->next=slow->next;           // deleting middle                     
        delete slow; 

        return head;                                      
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

    cout<<"Before deleting middle node -> ";
    obj.print(first);

    cout<<"After deleting middle node -> ";
    obj.deleteMiddle(first);
    obj.print(first);
    
    return 0;
}