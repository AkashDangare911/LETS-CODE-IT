/*You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.*/

#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    stack<char> st;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            st.push(s[i]);
        }
        else if (st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    string ans = "";
    while (st.size() != 0)
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string s = "abbaca";
    string a = solve(s);
    cout << a;
    return 0;
}