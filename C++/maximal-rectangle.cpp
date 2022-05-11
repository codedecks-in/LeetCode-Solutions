/* https://leetcode.com/problems/maximal-rectangle/ */
/* 
 * General idea: Store how many 1's are directly up starting at each location of the array.
 * So for example, if the matrix is [[1,0], [1,1]], then the array longest_up would 
 * look like [[1, 0], [2, 1]]. longest_up[0][0] is 1 because there is only one 1 starting 
 * at matrix[0][1] and going upwards. longest_up[1][0] is 2 because there are two 1's starting
 * at matrix[1][0] and going upwards. 
 *
 * Once we have this, we want to find the maximal rectangle whose bottom right corner ends
 * at a particular location matrix[i][j]. Then, if we can get the maximal rectangle over all
 * the rectangles that have bottom-right corners at matrix[i][j] for 0 <= i < n and 0 <= j < m, we can just return the best one. 
 *
 * In order to find the best rectangle whose bottom right corner ends at a particular location matrix[i][j],
 * we iterate to the left as long as the element on the left is a 1. Since we know what is the longest 
 * string of 1's going directly upwards for each location, if we just take the smallest one for each possible
 * location, we know that we are always going to have a rectangle of some sort. 
 * Difficulty: Hard
 *
 * Time: O(n*m)
 * Space: O(n*m)
 */
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int longest_up[n][m];
        int best = 0;//Stores the maximal rectangle
        //Create longest_ones matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longest_up[i][j] = 0;
                if (i == 0) {
                    longest_up[0][j] = matrix[0][j] - '0';
                } else if (matrix[i][j] == '1') {
                    longest_up[i][j] = longest_up[i - 1][j] + 1;
                }
                best = max(best, longest_up[i][j]);
            }
        }
        //Find the maximal rectangle 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int min_up = longest_up[i][j];
                for (int c = j; c >= 0 && matrix[i][c] == '1'; c--) {
                    min_up = min(min_up, longest_up[i][c]);
                    best = max(best, (j - c + 1) * min_up);
                }
            }
        }
        return best;
    }
};

