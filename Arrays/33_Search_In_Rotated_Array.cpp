/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/

#include <bits/stdc++.h>
using namespace std;
/*
#first approach
- find pivot element 
- check if arr[0]<= target <=arr[pivot] and apply binary search on left half
- else search in right half

#second approach
-every time check if left and right half is sorted or not 
-then check if arr[start]>= target && arr[mid]<=target, if yes then change the end pointer
    if not then target does not lie in the whole left array hence neglect it by changing start pointer
-now again check in right half that the element lies in it or not and change pointer accordingly.
-if not found return -1;
*/

class Solution
{
public:
    int search(vector<int> &nums, int target){

        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[start] <= nums[mid])
            {
                if (target >= nums[start] && target <= nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if (target >= nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
}
};
int main()
{
    Solution obj;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int pivot = obj.search(arr, target);
    cout << arr[pivot] << " " << pivot;
    return 0;
}