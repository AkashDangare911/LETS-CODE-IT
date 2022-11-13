
/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // brute force
    vector<int> intersection_Brute(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        set<int> s;
        for(int i : nums1)
        {
            for(int j : nums2)
            {
                if(i==j)
                {
                    s.insert(i);
                    break;
                }  
            }
        }
        
        for(int i : s)
            ans.push_back(i);
        
        return ans;
    }
    // two pointer approach using sorting
    vector<int> intersection_two_pointer(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> ans;
        set<int> s;

        int i=0;
        int j=0;

        while(i<n1 && j<n2)
        {
            int first=nums1[i];
            int second=nums2[j];

            if(first>second)
            {
                j++;
            }
            else if(first<second)
            {
                i++;
            }
            else if(first==second)
            {
                s.insert(first);
                i++;
                j++;
            }
        }
        for(int i : s)
            ans.push_back(i);
        
        return ans;
    }
};

int main()
{
    vector<int> arr1={1,2,2,1};
    vector<int> arr2={2,2};

    Solution obj;
    // obj.intersection_Brute(arr1,arr2);
    vector<int> final = obj.intersection_two_pointer(arr1,arr2);

    for(int i : final)
    cout<<i<<" ";
    return 0;
}