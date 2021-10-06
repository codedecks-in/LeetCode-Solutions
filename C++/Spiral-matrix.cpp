//Problem Number : 54
//Problem Name : Spiral Matrix
//Problem Statement : Given an m x n matrix, return all elements of the matrix in spiral order.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int left = 0, top = 0, down = matrix.size()-1, right = matrix[0].size()-1;
        
        while(left <= right && top <= down){            
            //From left to right on top side
            for(int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            top++;
            //From top to down on right side
            for(int i = top; i <= down; i++)
                res.push_back(matrix[i][right]);
            right--;
            if(top <= down){
            //From right to left on down side
                for(int i = right; i >= left; i--)
                    res.push_back(matrix[down][i]);
                down--;
            }
            if(left <= right){
            //From down to top on left side
                for(int i = down; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};

//This code is contributed by Nikhil-1503
