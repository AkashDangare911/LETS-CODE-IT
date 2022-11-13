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
    ListNode* getMid(ListNode* head) {
        ListNode* fast = head ->next;       
        ListNode* slow = head;    
        while(fast!= NULL && fast->next!= NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverseLL(ListNode *head)
    {   ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *nextt = NULL;
        
        while(cur!= NULL){
            nextt = cur -> next;
            cur ->next = prev;
            prev = cur;
            cur = nextt;
        }
        return prev;
    }
    // optimal approach
    bool isPalindrome(ListNode* head) {
        // step 1
        ListNode *middle = getMid(head);

        // step 2
        ListNode *temp = middle->next;
        middle ->next = reverseLL(temp);

        // step 3 - compare both halves
        ListNode *head1 = head;
        ListNode *head2 = middle->next;

        while(head2)
        {
            if(head1->data != head2->data)
                return false;
            
                head1 = head1->next;
                head2 = head2->next;
        }

        // step 4 - repeat step 2   (optional)
        temp = middle->next;
        middle ->next = reverseLL(temp);

        return true;
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
    ListNode *fourth = new ListNode(2);     third ->next = fourth;
    ListNode *fifth = new ListNode(1);      fourth ->next = fifth;
    fifth->next = nullptr;
    
    obj.print(first);
    bool ans = obj.isPalindrome(first);
    cout<<ans;

    return 0;
}