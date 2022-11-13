/*Given the head of a singly linked list, reverse the list, and return the reversed list.

STEPS
1) save next of current
2) change direction of link
3) make prev to current
4) move current to its saved next
*/
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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *nextt = NULL;
        
        while(current!= NULL)
        {
            nextt = current -> next;
            current ->next = prev;
            prev = current;
            current = nextt;
        }
        
        return prev;
    }
    // extra space
    ListNode* reverseListWithStack(ListNode* head) {
        stack<ListNode*> s;
        ListNode *temp = head;

        while(temp != NULL){
            s.push(temp);
            temp=temp->next;
        }

        head=s.top();
        temp = head;
        s.pop();

        while(!s.empty())
        {
            ListNode *t =s.top();
            head->next = t;
            head = head->next;
            s.pop();
        }
        head->next = NULL;
        return temp;
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

    
    obj.print(first);
    obj.print(obj.reverseList(first));

    return 0;
}
