/*Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

Return the leftmost pivot index. If no such index exists, return -1.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =0;
        for(int i : nums)
            sum +=i;
    
        int lsum = 0;
        int rsum = sum;

        for(int i=0;i<nums.size();i++)
        {
            
            rsum -=nums[i];
            if(rsum == lsum){
                return i; } 
            else{
                lsum += nums[i];
           }
        }
        return -1;
    }
};
int main()
{
    Solution obj;
    vector<int> arr={1,7,3,6,5,6};
    int pivot = obj.pivotIndex(arr);
    cout<<"Pivot is : "<<pivot;
    return 0;
}