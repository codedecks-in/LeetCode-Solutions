#include<iostream>
#include<vector>
//#######Approach######
// 1.We need a vector of vector , so, first we will make a string.
// 2.Then we will check that according to the current vector can we push the new string formed.
// 3.For making new string we will check in which index of the string the Q must be placed. For which we will put Q at every index.
// 4.If we are able to find the string, we push it to vector and call a recursion to push the next string.
// 5.When the size of vector will be n, we will push it to the vector<vector>.
using namespace std;
class Solution {
    vector<vector<string>>ans;
    bool check(vector<string>&v ,int ind ,int n){
        if(v.empty()) return true;
        for(int i=0 ; i<v.size() ; i++){
            if(v[i][ind]=='Q') return false;
        }
        int y=ind-1;
        int x =v.size()-1;
        while(x>=0 && y>=0){
            if(v[x][y] == 'Q') return false;
            x--;y--;
        }
        y=ind+1;
        x =v.size()-1;
        while(x>=0 && y<n){
            if(v[x][y] == 'Q') return false;
            x--;y++;
        }
        return true;
    }
    void recur(int n,string &s , vector<string>&v ){
        if(v.size() == n) {ans.push_back(v); return;}
        for(int i=0 ; i<n ; i++){
                
            if(check(v, i, n)){
                s[i] = 'Q';
                v.push_back(s);
                s[i] = '.';
                recur(n,s,v);
                v.pop_back();
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0 ; i<n; i++) s+='.';
        vector<string>v;
        recur(n,s,v );
        return ans;
    }
};