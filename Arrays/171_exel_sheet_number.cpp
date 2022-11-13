/*Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:
A -> 1
B -> 2

AA -> 27
AB -> 28 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        if(n==1)
            return columnTitle[0] - 'A' + 1 ;
        
        int sum = 0;
        long temp = 26;
        for(int i = n-2;i>=0;i--)
        {
            int v = columnTitle[i] - 'A' + 1;
            sum = sum + v * temp ;
            temp = temp *26;        
        }
        sum += columnTitle[n-1] - 'A' + 1 ;         // adding last digit element to ans
        return sum;
    }
};

int main()
{
    string s = "AAA";
    Solution obj;
    cout<<"Exel sheet number of "<<s<<" is : "<<obj.titleToNumber(s);
    return 0;
}