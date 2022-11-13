/*Given the head of a linked list, remove the nth node from the end of the list and return its head.*/

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
    // 0ms, fastest solution from chart
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;

        for(int i = 0 ; i < n ; i++)
            fast = fast->next;
        
        if(!fast) return head->next;        // if first is going to delete

        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int l = 0;
        while(temp)
        {
            temp = temp->next;
            l++;
        }
        // if node to be deleted is the head node itself
        if(l==n || l==1)
            return head->next;      // the only case to think upon
        
        int z = l-n-1;
        temp = head;
        
        while(z>0)
        {
            temp = temp->next;
            z--;
        }

        temp-> next = temp->next->next;
        return head;
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

    ListNode *ans = obj.removeNthFromEnd(first,3);
    return 0;
}