/*Given an m x n matrix, return all elements of the matrix in spiral order.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // LOVE BABBAR
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int startRow = 0;
        int endRow = m-1;
        int startCol = 0;
        int endCol = n-1;

        int count =0;
        int total = m * n;
        
        while(count < total)
        {
            // in case if count becomes greater than total but still gets executed in for loop , hence we are checking count<total in every iteration of every for loop

            for(int i=startCol;count<total && i<=endCol;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            for(int i=startRow;count<total && i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i=endCol;count<total && i>=startCol;i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for(int i=endRow;count<total && i>=startRow;i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int> >v = {{1,2,3},{4,5,6},{7,8,9}};
    vector <int> ans = obj.spiralOrder(v);

    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}