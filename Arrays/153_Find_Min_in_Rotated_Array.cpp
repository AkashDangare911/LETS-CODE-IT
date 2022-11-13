/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.*/

#include <bits/stdc++.h>
using namespace std;

int findMinLinear(vector<int> &nums)          // linear search (not recommended)
{
    int size = nums.size();
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            return nums[i];
        }
    }
    return nums[0];         // if not returned by function then first element itself if the smallest
}

int findMinBinary(vector<int> &nums)        // binary search
{
    int start = 0;
    int end = nums.size() - 1;

    int ans = 0;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return nums[start];
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << "By binary search : "<<findMinBinary(arr)<<endl;
    cout << "By linear search : "<<findMinLinear(arr)<<endl;
    return 0;
}