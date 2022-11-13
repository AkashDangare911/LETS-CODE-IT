/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.*/

#include<bits/stdc++.h>
using namespace std;


class ListNode {
public:
    ListNode *next ;
    int val ;

    ListNode(){
        next = nullptr;
        int val = 0;
    }
    ListNode(int d){
        next = nullptr;
        val = d;
    }
    ListNode(ListNode *n , int d){
        next = n;
        val = d;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return nullptr;
        
        ListNode *ans = new ListNode();
        ListNode *head = ans;
        ListNode *prev = ans;
        
        while(list1 && list2)
        {
            int d1 = list1-> val;
            int d2 = list2-> val;
            
            if( d1 < d2 )
            {
                ans->val = d1;
                list1 = list1->next;
            }
            else
            {
                ans->val = d2;
                list2 = list2->next;
            }
            ListNode * temp=new ListNode();
            ans->next = temp;
         
            ans = ans->next;
        }
        
        while(list1)
        {
            ans -> val = list1-> val;
            list1 = list1-> next;
            
            ListNode * temp=new ListNode();
            ans->next = temp;
            prev=ans;
            
            ans = ans->next;
        }
        
        while(list2)
        {
            ans -> val = list2-> val;
            list2 = list2-> next;
            ListNode * temp=new ListNode();
            ans->next = temp;
            prev=ans;
            ans = ans->next;
        }
        prev->next=nullptr;
        
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

    ListNode *first2 = new ListNode(4);        
    ListNode *second2 = new ListNode(5);      first2 ->next = second2;
    ListNode *third2 = new ListNode(6);       second2 ->next = third2;

    ListNode * ans = obj.mergeTwoLists(first,first2);
    cout<<"Sorted list is : ";
    while(ans)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    return 0;
}