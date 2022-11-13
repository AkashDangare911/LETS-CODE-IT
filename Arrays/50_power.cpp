/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
long double Pow(double x, int n) 
{
    if(x==1 || n==0)
    return 1;
    bool isNegative=false;
    if(n<0)
    {
        n=(-1)*n;
        isNegative = true;
    }
    double ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*x;
    }
    if(isNegative)
        ans=(double) 1/ (double)ans;

    return ans;
}
// OPTIMISED
long double myPow(double x, int n) 
{
    if(x==1 || n==0)
    return 1;
    double ans=1;
    long long n2=n;
    
    if(n<0)
    {
        n2=(-1)*n2;         // check for negative power
    }
    while(n2>0)
    {
        if(n2%2)
        {
            ans=ans*x;          // if odd then, multiply with number and decreasing power value by 1
            n2=n2-1;
        }
        else
        {
            x=x*x;
            n2=n2/2;            // if even then, squaring the number and decreasing power to half
        }
    }
    if(n<0)
    {
        ans=(double) 1/ (double)ans;   
    }
    return ans;
}
int main()
{
    cout<<Pow(2,-10);
    // cout<<myPow(2,10);
    return 0;
}