/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.*/

#include <bits/stdc++.h>
using namespace std;

 bool isPowerOfTwo1(int n)  // brute force 
 {
    int ans=1;
    for(int i=0;i<31;i++)
    {
        if(ans==n)
        {
            return true;
        }
        if(ans<INT_MAX/2)
        {
            ans*=2;
        }
    }
    return false;
 }

bool isPowerOfTwo2(int n)       // optimized
{
    if(n<=0)
        return false;
    int count=0;

    while(n!=0)
    {
        if(n&1)
        {
            count++;
        }
        n=n>>1;
        if(count>1)
            return false;
    }
    return true;
}

int main() {
	    int n=16;
        cout<<isPowerOfTwo2(n);
	return 0;
}
