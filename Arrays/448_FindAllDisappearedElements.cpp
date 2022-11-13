/*Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // trick : we negate the value present at every index, but
    //         if the element is absent then we can't get the element of that index and hence the element 
    //         at that index remains positive and that's the ans...
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            int index=abs(nums[i]) - 1;
            nums[index] = -1 * abs(nums[index]);
        }
        
        for(int i=0;i<n;i++)
        {
            if (nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }

    vector <int> find_Using_Extra_Space(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> counter(n+1);
        for(int i=0;i<n;i++){
            counter[nums[i]]++;
        }
        
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            if(counter[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> arr={4,3,2,7,8,2,3,1};

    obj.findDisappearedNumbers(arr);
    obj.find_Using_Extra_Space(arr);

    return 0;
}