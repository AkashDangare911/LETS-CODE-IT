/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.*/

#include<bits/stdc++.h>
using namespace std;
/*
Approach 1) use sorting
Approach 2) count frequency and insert elements into original vector
Approach 3) use below solution
*/
class Solution {
public:
    vector<int> sortColors(vector<int>& a) 
    {
        int l = 0;
        int  r = a.size() - 1;

        for(int i = 0; i <= r; i++) 
        {
            if(a[i] < 1)
            {
                swap(a[i], a[l]);
                l++;
            } 
            else if(a[i] > 1) 
            {
                swap(a[i], a[r]);
                r--;
                i--;        // remember this line
            }
        }
        return a;
    }
};

int main()
{
    Solution obj;
    vector <int> arr = {2,0,2,1,1,0};
    
    cout<<"Before -> ";
    for(int i : arr)    cout<<i<<" ";
    cout<<endl;

    obj.sortColors(arr);
    cout<<"After -> ";
    for(int i : arr)    cout<<i<<" ";
    return 0;
}