/*An array arr a mountain if the following properties hold:

There exists some i with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.*/

#include <bits/stdc++.h>
using namespace std;

int peakLinear(int arr[],int size)              // O(n) using linear search
{
    int i=0;
    while(arr[i]<arr[i+1])
    {
        i++;
    }
    return i;
}
int peak(int arr[],int size)                   // O(logn) using binary search
{
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;

    // NOTE : this mountain array consists of repeated element , so in this case we are comparing adjacent elements and not the start-end-mid elements
    while(s<e)
    {
        if(arr[mid]<arr[mid+1])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return e;   // can return mid also
}

int main()
{
   int arr[10]={4,6,9,23,25,29,18,10,6,1};
   int s=sizeof(arr)/sizeof(arr[0]);
   cout<<"The Peak index is "<<peakLinear(arr,s)<<endl;
   cout<<"The Peak index is "<<peak(arr,s);
    return 0;
}