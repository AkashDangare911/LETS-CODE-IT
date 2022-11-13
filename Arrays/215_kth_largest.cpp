/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
You must solve it in O(n) time complexity.*/

#include<bits/stdc++.h>
using namespace std;

// Another Approach - sorting -> return arr[k-1];

class Solution {
public:
    
    int findKthLargest(vector<int> arr, int k) {
        
        // create max heap and push all elements
        priority_queue <int> p;
        for(int i : arr)
            p.push(i);

        k--;
        
        // pop k elements 
        while(k)
        {
            p.pop();
            k--;
        } 
        return p.top();
    }
};

int main()
{
    Solution obj;
    vector <int> v = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    
    cout<<obj.findKthLargest(v,k);

    return 0;
}