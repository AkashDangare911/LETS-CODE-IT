/*
GIVEN AN INTEGER ARRAY IN SORTED FASHION AND WE HAVE TO FIND LEFTMOST AND RIGHTMOST POSITIONS OF AN ELEMENT THEN USE BELOW APPROACH
- we can use linear search and store first occurence as min and last as max . Then comparing with every occurence index .==> O(n)
- use binary search to find element and 
    -for left occurence , if element is found then , store mid in a variable and update end as mid - 1
    -for right occurence , if element is found then ,store mid in a variable and update start as mid + 1
    -total occurences (frequency) => (right-left+1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leftOcc(vector<int>& arr,int key){
    int start=0;
    int end=arr.size()-1;
    int mid=start+(end-start)/2;

    int i=0;
    int ans=-1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;                    // ans stores left occurence of element (-1 if elements if absent)
            end=mid-1;
        }
        else{                           // 0 1 2  3  4  5  6  7  8  9
            if(arr[mid]<key)            // 2 5 9 14 14 14 14 77 144 200
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

int rightOcc(vector<int>& arr,int key){
    int start=0;
    int end=arr.size()-1;
    int mid=start+(end-start)/2;

    int i=0;
    int ans=-1;
    while(start<=end)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            start=mid+1;
        }
        else{                           
            if(arr[mid]<key)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        mid=start+(end-start)/2;
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
       vector <int> ret;
        ret.push_back(leftOcc(nums,target));
        ret.push_back(rightOcc(nums,target));
       
        return ret;
    }
};
int main()
{
    Solution obj;
    vector <int> arr={2,5,9,14,14,14,14,77,144,200};
    int key=14;
    int left = obj.leftOcc(arr,key);
    int right= obj.rightOcc(arr,key);

    cout<<"Left occurence is :"<<left<<endl;
    cout<<"Right occurence is :"<<right<<endl;
    cout<<"Total occurences of "<<key<<" are :"<<right-left+1;
    return 0;
}