//https://leetcode.com/problems/dungeon-game/
////Difficulty Level: Hard
//Tags: Dynamic Programming
//Time complexity: O(m*n)
//Space complexity: O(m*n)
//bottom-up DP approach
class Solution 
{
    public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m = dungeon.size();
        if(r==0)                //empty dungeon
           return 0;

        int n = dungeon[0].size();
        
        //dp[i][j] --> min health req to reach the princess with starting cell as (i,j) -1
        vector<vector<int> > dp(r, vector<int>(c));

        for (int i = m-1; i>=0; i--)          //traversing the array from bottom
        {
            for (int j = n-1; j>=0; j--)
            {
                //if starting from last cell, 
                //if value at last cell is -ve, health req. is 1+abs(value)
                //if value at last cell is +ve, health req. is 0+1
                if (i == m-1 && j == n-1)     
                {
                    dp[i][j] = min(0, dungeon[i][j]);
                }

                //if starting from last row,
                //total health req. is sum of curr cell value and health req. at next cell
                //if the sum is +ve, health req. is 0+1
                //if the sum is -ve, health req. is 1+abs(sum)
                else if (i == m-1)
                {
                    dp[i][j] = min(0, dungeon[i][j]+dp[i][j+1]);
                }

                //if starting from last column,
                //total health req. is sum of curr cell value and health req. at next cell
                //if the sum is +ve, health req. is 0+1
                //if the sum is -ve, health req. is 1+abs(sum)
                else if (j == n-1)
                {
                    dp[i][j] = min(0, dungeon[i][j]+dp[i+1][j]);
                }

                //if starting from any other cell,
                //make a choice to go to the cell with less req. health(more positive dp value) after the curr cell
                //the req. health is either 0 or sum of the curr cell value and health req. at next chosen cell
                else
                {
                    dp[i][j] = min(0, dungeon[i][j]+max(dp[i][j+1],dp[i+1][j]));
                }
            }
        }
        //actual starting point is (0,0), so return abs(dp(0,0))+1
        //1 is added because the knight needs to have atleast 1 health to survive, else he will die
        return abs(dp[0][0])+1;
    }
};
