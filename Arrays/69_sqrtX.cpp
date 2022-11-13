/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.*/

#include <bits/stdc++.h>
using namespace std;
int sqRootBruteForce(int x)
{
    if(x<2)
        return x;

    for(long long i=2;i<=x;i++){
        if(x == i*i)
        return i;
        
        else if(i*i >x)
            return i-1;
    }
    return 0;
}
int sqRoot(int x)
{
    int s=0;
    int e=x;
    long mid=s+(e-s)/2;
    // reduce search space in each iteration
    while(s<=e)
    {
        long m=mid*mid;
        if(m==x)
        {
            return mid;     // if condition matches then return ans as mid
        }
        else if(m>x)
        {
            e=mid-1;        // ans lies in left half
        }
        else{
            s=mid+1;        // ans lies in right half
        }
        mid=s+(e-s)/2;
    }
    return mid-1;       // if do not matches then return the previous integer of mid
}
int main()
{
    int x=2501;
    int ans=sqRootBruteForce(x);
    cout<<ans;
    return 0;
}