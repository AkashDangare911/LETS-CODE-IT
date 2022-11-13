/*Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int mx=*max_element(arr.begin(),arr.end());     //getting max element
        vector<int> v(1+mx,0);          // array to store max elements' count
        
        for(int i=0;i<arr.size();i++)
            v[arr[i]]++;
       
        // v[0] will be always zero due to constrains given
        for(int i=1;i<v.size();i++)
        { 
            if(!v[i])
              k--;
               
            if(k<1)     // returning kth missing element
                return i;
        }
        // if k th element is greater than max element  then,
        // we have to return (max element + remaining kth elements) b'cause elements are in sorted           
        // increasing order
        
        int ans=mx+k;
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2,3,4,7,11};
    int k=5;
    int ans = obj.findKthPositive(arr,k);
    cout<<"Kth missing positive is : "<<ans;
    return 0;
}