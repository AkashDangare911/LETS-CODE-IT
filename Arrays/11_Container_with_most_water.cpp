/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=height.size();
        int left=0;
        int right=s-1;
        
        int maxArea=0;
        
        while(left<right)
        {
            int area=0;
            int l=height[left];
            int r=height[right];

            area=min(l,r)*(right-left);
            if(l<r){
                left++;
            }
            else{
                right--;
            }
            maxArea=max(area,maxArea);
        }
        
        return maxArea;
    }
};

int main()
{
    Solution obj;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<"Maximum water stored in container is : "<<obj.maxArea(height);
}