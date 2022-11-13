/*Given an array, rotate the array to the right by k steps, where k is non-negative.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // LOVE BABBAR
    void Rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans(n);
        
        for(int i = 0;i<n;i++)
        {
            int index=i+k;
            ans[index%n]=nums[i];
        }
        nums = ans;
    }
};
int main()
{
    // Got TLE on using insert and erase functions
    Solution obj;
    vector<int> v={1,2,3,4,5,6,7};
    obj.Rotate(v,3);

    for(int i : v)
        cout<<i<<" ";
    return 0;
}