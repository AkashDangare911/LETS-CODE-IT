#include<bits/stdc++.h>
using namespace std;
vector <int> solve(vector <int> arr,int s)
{
	int i=s;
	while(i>=0)
	{
		if(arr[i]<9)					// if 135 then only add 1 and return 136
		{
			arr[i]+=1;
			return arr;
		}
		else
		{
			arr[i]=0;					// 149 then change 9 to 0 and in next iteration change 4 to 5
		}
		i--;
	}								// if 999 occurs then make all digits as 0 and 		(000)
	arr[0]=1;						// at end of loop change first element to 1			(100)
	arr.push_back(0);				// add another zero at end							(1000)
	return arr;
}
int main()
{
	vector <int> arr={9,9};
	int s=arr.size();
	vector <int> ans = solve(arr,s);

	for(int i : ans)
	cout<<i<<" ";

	return 0;
}