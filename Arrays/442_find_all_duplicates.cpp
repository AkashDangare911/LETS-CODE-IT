/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // extra space of O(n)    -> O(n+n) time
    vector<int> findUsingSpace(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i : nums)
            mp[i]++;

        for(pair <int,int> p : mp)
        {
            if(p.second>1)
                ans.push_back(p.first);
        }
        return ans;
    }
    // without extra space and time -> O(n)
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int index=abs(nums[i])-1;
            if(nums[index]<0)
            {
                ans.push_back(index+1);   
            }
            nums[index]=-1*nums[index];
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {4,3,2,7,8,2,3,1};
    vector <int> ans1 = obj.findDuplicates(arr);
    vector <int> ans2 = obj.findUsingSpace(arr);
    for(int i : ans2)
        cout<<i<<" ";
    return 0;
}