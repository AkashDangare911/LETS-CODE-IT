/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;

    ListNode()
    {
        next = nullptr;
        int val = 0;
    }
    ListNode(int d)
    {
        next = nullptr;
        val = d;
    }
    ListNode(ListNode *n, int d)
    {
        next = n;
        val = d;
    }

    // tuf
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *temp = ans;

        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = 0;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            sum += carry;

            carry = sum / 10;
            sum = sum % 10;

            ListNode *t = new ListNode();
            t->val = sum;

            ans->next = t;
            ans = ans->next;
        }

        return temp->next;
    }
};

int main()
{
    ListNode obj;

    ListNode *l1 = new ListNode(2);      
    ListNode *second = new ListNode(4);     l1 ->next = second;
    ListNode *third = new ListNode(3);      second ->next = third;
    

    ListNode *l2 = new ListNode(5);        
    ListNode *fourth = new ListNode(6);      l2 ->next = fourth;
    ListNode *fifth = new ListNode(4);       fourth ->next = fifth;

    ListNode * ans = obj.addTwoNumbers(l1,l2);
    // 342 + 465 = 807

    while(ans)
    {
        cout<<ans->val;
        ans = ans->next;
    }
    return 0;
}