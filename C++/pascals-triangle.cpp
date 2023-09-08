// runtime : 3ms
// memory : 6.7 MB
// complexity : O(n^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        int k = 0;

        for(int i=0; i<numRows; i++){
            result[i].resize(i+1);
            result[i][0] = 1;
            result[i][k] = 1;

            for(int j=1; j<k; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
            k++;
        }
        return result; 
    }
};