class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i = 0; i < matrix.size(); i++){
             for(int j = i; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
             }
        } 

        for(int i=0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
//         int n=matrix[0].size();
//         int mat2[n][n];
        
//         for(int i=0;i<n;++i){
//             for(int j=0;j<n;++j){
//                 mat2[j][n-i-1]=matrix[i][j];
//             }
//         }
        
//         for(int i=0;i<n;++i){
//             for(int j=0;j<n;++j){
//                 matrix[i][j]=mat2[i][j];
//             }
//         }
    }
};
