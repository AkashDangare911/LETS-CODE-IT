/*Given an integer n, return the number of prime numbers that are strictly less than n.*/

#include<bits/stdc++.h>
using namespace std;
/*
- create bool array of size of given no. 'n' and mark all positions as 'true'
- start a loop starting from 2 to 'n'
- firstly start with 2 and mark all multiples of 2 as false;
- then start with 3 and check if true or not . If true, then increase count and  mark all multiples of 3 as false;
- continue for all nos less than 'n'
- n*log(logn)
*/
int sieve(int n)
{
    vector<bool> pr(n,true);
    int count=0;
    pr[0]=pr[1]=false;          // make them false as they are not prime

    for(int i=0;i<n;i++)
    {
        if(pr[i])           // check if it's position is true or not
        {
            count++;
            for(int j=i*i;j<n;j=j+i)          // run loop in multiples of i variable
            {
                pr[j]=false;                // and make all multiples as false
            }
        }
    }
    cout<<endl;
    return count;
}
int main()
{
    int n=100;
    cout<<"Total nos are :"<<sieve(n);
    return 0;
}