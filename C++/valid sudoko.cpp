class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //checking rows
        for(int i=0;i<9;++i){
            map<char,int> mpp;
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    mpp[board[i][j]]++;
                    if(mpp[board[i][j]]>1){
                        return false;
                    }
                }
            }
        }
        //checking columns
        for(int i=0;i<9;++i){
            map<char,int> mpp;
            for(int j=0;j<9;++j){
                if(board[j][i]!='.'){
                    mpp[board[j][i]]++;
                    if(mpp[board[j][i]]>1){
                        return false;
                    }
                }
            }
        }
        //checking boxes
        for(int k=0;k<9;k+=3){
            //first box
            map<char,int> mpp1;
            for(int i=k;i<k+3;++i){
                for(int j=0;j<3;++j){
                    if(board[i][j]!='.'){
                        mpp1[board[i][j]]++;
                        if(mpp1[board[i][j]]>1){
                            return false;
                        }
                    }
                }
            }
            //second box
            map<char,int> mpp2;
            for(int i=k;i<k+3;++i){
                for(int j=3;j<6;++j){
                    if(board[i][j]!='.'){
                        mpp2[board[i][j]]++;
                        if(mpp2[board[i][j]]>1){
                            return false;
                        }
                    }
                }
            }
            //third box
            map<char,int> mpp3;
            for(int i=k;i<k+3;++i){
                for(int j=6;j<9;++j){
                    if(board[i][j]!='.'){
                        mpp3[board[i][j]]++;
                        if(mpp3[board[i][j]]>1){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
