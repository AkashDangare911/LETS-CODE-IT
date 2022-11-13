/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.*/

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

    // best solution with 0ms
    ListNode* middle0ms(ListNode* head) {
        ListNode* fast = head ->next;       // running with speed 2x
        ListNode* slow = head;              // running with speed x

        while(fast!= NULL && fast->next!= NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        // when end is at actual end , the middle will be at actual middle -> hence the answer
        return slow;
    }

    // my solution
    ListNode* middleNode(ListNode* head) {
        
        ListNode *temp = head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp = temp -> next;
        }
        int t = count;
        count = count/2;
        while(count){
                head = head ->next;
                count--;
            }
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
    // ListNode *fifth = new ListNode(5);      fourth ->next = fifth;

    // 1 - 2 - 3- 4 - 5     => middle =3
    // 1 - 2 - 3 - 4        => middle =3
    obj.print(first);
    ListNode *ans = obj.middleNode(first);
    cout<<ans->data;
    return 0;
}