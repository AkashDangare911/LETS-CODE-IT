/*A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

e.g., 28 = 1 + 2 + 4 +7 + 14
Given an integer n, return true if n is a perfect number, otherwise return false.*/

#include<bits/stdc++.h>
using namespace std;
// 
class Solution {
public:
    // simple approach
    bool PerfectNumber(int num) {
        int ans=0;
        num = num/2;
        for(int i=1;i<=num;i++)
        {
            if(!(num%i))
                ans+=i;
        }
        
        return ans==num;
    }
    //optimised
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int s=1;
        
        for(int i=2; i<sqrt(num); i++){
            // if num%i!=0 the add i to sum and also add (num/i) , so that we don't have to check for it's half portion again
            if(!(num%i)){
                s+= i;
                s += num/i;
            }
        }   
        return s==num;
    }
};

int main()
{
    Solution obj;
    obj.checkPerfectNumber(28);
    obj.PerfectNumber(6);
    return 0;
}