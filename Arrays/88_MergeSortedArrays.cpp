/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // using extra space
    void MergeUsingSpace(vector<int>& arr1,vector<int>& arr2)
    {
        int s1=arr1.size();
        int s2=arr2.size();
        vector<int> ans;        // to store final ans

        int i=0;int j=0;

        while(i<s1 && j<s2)
        {
            if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i<s1-s2)    ans.push_back(arr1[i++]);
        while(j<s2)       ans.push_back(arr2[j++]);

        for(int i : ans)
        cout<<i<<" ";
        cout<<endl;
    }
    void MergeWithoutSpace(vector<int>& arr1,vector<int>& arr2)
    {
        int s1=arr1.size();
        int s2=arr2.size();

        int i=s1/2 ;
        int j=s2-1;
        int k=s1-1;
        while(i>=0 && j>=0)
        {
            if(arr1[i]>arr2[j]){
                arr1[k] = arr1[i--];
                k--;
            }
            else{
                arr1[k] = arr2[j--];
                k--;
            }
        }
        while(i>=0)    arr1[k--] = arr1[i--];
        while(j>=0)    arr1[k--] = arr2[j--];

        for(int i : arr1)
            cout<<i<<" ";
            cout<<endl;
    }
};
int main()
{
    Solution obj;
    vector<int> arr1 = {1,3,4,8,9,11,65,78,0,0,0,0,0,0,0};
    vector<int> arr2 = {2,3,4,6,7,9,22};

    obj.MergeUsingSpace(arr1,arr2);
    obj.MergeWithoutSpace(arr1,arr2);

    return 0;
}