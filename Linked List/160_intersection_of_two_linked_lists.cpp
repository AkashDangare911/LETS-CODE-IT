/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.

Note that the linked lists must retain their original structure after the function returns.*/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1=0;
        int s2=0;
        ListNode *temp = headA;
        while(temp)
        {
            temp=temp->next;
            s1++;
        }
        temp = headB;
        while(temp)
        {
            temp=temp->next;
            s2++;
        }
        ListNode *start = NULL;
        
        if(s1<s2){
            start=headB;
            temp = headA;
            
            int inc = abs(s1-s2);
            while(inc)
            {
                start = start->next;
                inc--;
            }

            while(start){
                if(start == temp)
                    return start;
                start = start->next;
                temp = temp ->next;
            }
        }   
        else{
            start=headA;
            temp = headB;
            
            int inc = abs(s1-s2);
            while(inc)
            {
                start = start->next;
                inc--;
            }

            while(start){
                if(start == temp)
                    return start;
                start = start->next;
                temp = temp ->next;
            }
        }    
        return nullptr;
    }
};

int main()
{
    ListNode obj;

    ListNode *first1 = new ListNode(4);      
    ListNode *second1 = new ListNode(1);     first1 ->next = second1;
    ListNode *third1 = new ListNode(8);      second1 ->next = third1;

    ListNode *first2 = new ListNode(5);     
    ListNode *second2 = new ListNode(6);    first2 ->next = second2;
    ListNode *third2 = new ListNode(1);     second2 ->next = third2;
    third2 -> next = third1;

    ListNode *fourth1 = new ListNode(4);     third1 ->next = fourth1;
    ListNode *fifth1 = new ListNode(5);      fourth1 ->next = fifth1;

    ListNode *ans = obj.getIntersectionNode(first1,first2);
    cout<<ans;
    
    return 0;
}
