/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int num=0;
        for (int i:nums)
        {
            num=num^i;
        }
        return num;
    }

    int singleNumberUsingSpace(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i : nums)
            mp[i]++;

        for(pair<int,int> p : mp)
        {
            if(p.second ==1)
                return p.first;
        }
        return -1;
    }

};

int main()
{
    vector<int> v = {4,1,2,1,2};
    Solution obj;
    cout<<obj.singleNumberUsingSpace(v);
    
    return 0;
}
