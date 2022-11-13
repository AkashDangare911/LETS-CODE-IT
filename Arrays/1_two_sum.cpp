/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    // using space
    vector<int> twoSumUsingMap(vector<int>& nums, int target) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int key = target - nums[i];
            
            if(mp.find(key) != mp.end())
            {           
                ans.push_back(i);
                ans.push_back(mp[key]);
            }
            // if ans is not present in map then add it to map
            mp[nums[i]] = i;
        }
        
        return ans;
    }
    
    // O(n2)
     vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=nums.size()-1;j>i;j--)
            {
                if( (nums[i]+nums[j]) == target)
                {
                    ans.pb(i);
                    ans.pb(j);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> v = {2,7,11,15};
    
    vector <int> ans = obj.twoSum(v,9);
	cout<<ans[0]<<" "<<ans[1];
    
    return 0;
}