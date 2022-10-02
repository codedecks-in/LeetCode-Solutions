

// Leetcode Problem number : 36


class Solution {
public:
    bool ans = true;
    bool isvalid(map<char,int>& m){
        for(auto x : m){
            if(x.second >1){
                return false;
            }
        }
        return true;
    }
    void print(map<char,int>& m){
        for(auto x : m){
            cout<<x.first<<" "<<x.second<<"\n";
        }
        cout<<"\n";
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> m,m1,m3,m4,m5;
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
              if(board[i][j] != '.')
                    m[board[i][j]]++;
              if(board[j][i] != '.')
                     m1[board[j][i]]++;
             
                 if(j<3){
                 if(board[i][j] != '.')
                     m3[board[i][j]]++;
                  }else if(j>2 && j<6){
                     if(board[i][j] != '.')
                        m4[board[i][j]]++;
                }else{
                     if(board[i][j] != '.')
                         m5[board[i][j]]++;
              }
              
            }
            ans = isvalid(m);
            m.clear();
            if(ans == false){
                return false;
            }
            ans = isvalid(m1);
            m1.clear();
            if(ans == false){
                return false;
            }
            
            if((i+1) %3 == 0){
                ans = isvalid(m3);
                m3.clear();
                if(ans == false){
                    return false;
                }
                ans = isvalid(m4);
                m4.clear();
                if(ans == false){
                    return false;
                }
                ans = isvalid(m5);
                m5.clear();
                if(ans == false){
                    return false;
                }
            }
            
        }
        
        
        
        
        return ans;
    }
};
