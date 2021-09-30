class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size() != r*c) return mat;
        vector<int> v;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                v.push_back(mat[i][j]);
            }
        }
        int k=0;
        vector<vector<int>> vnew;
        vector<int> input;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                input.push_back(v[k++]);
            }
            vnew.push_back(input);
            input.clear();
        }
        return vnew;
    }
};
