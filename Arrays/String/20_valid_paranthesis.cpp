/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) 
        {
            char c=s[i];
            if (c=='(' || c=='{' || c=='[') {
                st.push(c);
            }
            else if(!st.empty()){
                if (c==')' && st.top()=='(') {
                    st.pop();
                }
                else if (c==']' && st.top()=='[') {
                    st.pop();
                }
                else if (c=='}' && st.top()=='{') {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        
        if (st.empty())
            return true;

        return false;
    }
};

int main()
{
    Solution obj;
    string ss="{{(){}}}";
    cout<<obj.isValid(ss);
    return 0;
}