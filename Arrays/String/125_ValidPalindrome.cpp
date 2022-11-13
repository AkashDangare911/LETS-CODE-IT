/*
125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {

        int l=s.length();
        if(l==0)
            return true;

        // store in temp variable 
        string str="";
        for(int i=0;i<l;i++)
        {
            char letter=tolower(s[i]);
            if( (letter>='a' && letter<='z') ) //can use ascii values of characters from 97 to 122
            {
                str+=letter;
            }
            else if((s[i]>='0' && s[i]<='9'))               // 46 to 57
            {
                str+=s[i];
            }
        }

        // check if palindrome
        int start=0;
        int end=(str.length()-1);
        while(start<=end)
        {
            if(str[start]!=str[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    string s="a man is a si nama";
    Solution obj;
    if(obj.isPalindrome(s))
    {
        cout<<"Given String is Palindrome ...";
    }
    else{
        cout<<"Sring is not Palindrome...";
    }
    return 0;
}