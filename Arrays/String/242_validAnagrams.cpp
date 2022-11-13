/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // using map
    bool isAnagramMap(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        if(n1!=n2)
            return false;
        
        unordered_map <char,int> mp;
 
        for(int i : s)
            mp[i]++;
       
        for(int j : t)
            mp[j]--;

        // checking frequency
        for(pair<char,int> p : mp)
        {
            if(p.second != 0)
                return false;
        }
        return true;
    }

    //using vectors
    bool isAnagramVect(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1!=n2)
            return false;
        
        vector<int> first(26);
        
        for(int i=0;i<n1;i++)
        {
            int index = s[i] -'a';
            first[index]++;
            
            index = t[i] -'a';
            first[index]--;
        }
        
        for(int i : first)
        {
            if(i != 0)
                return false;
        }
        
        return true;
    }
};

int main()
{
    Solution obj;
    string s = "medical";
    string t = "decimal";

    cout<<"Is anagram using map : "<<obj.isAnagramMap(s,t)<<endl;
    cout<<"Is anagram using vector : "<<obj.isAnagramVect(s,t)<<endl;
    return 0;
}