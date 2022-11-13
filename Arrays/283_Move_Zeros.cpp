/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // we have to preserve the order of elements
    void moveZeroes(vector<int>& arr) {
        
        int n=arr.size();
        int i=0;
        int j=0;
        
        while(j<n)
        {
            if(arr[j]!=0)
            {
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
    }
    void print(vector<int> & arr)
    {
        for (int i : arr)
        cout<< i << " ";
    }
};

int main()
{
    Solution obj;
    vector<int> v={0,1,3,4,0,0,12};
    obj.moveZeroes(v);

    obj.print(v);
    return 0;
}