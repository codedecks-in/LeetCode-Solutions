class Solution {
    
    // Function to calculate the no. of ways using dynamic programming
    int f(int i, string s, vector<int>& dp){
        
        //i acts as a pointer pointing to characters of the string s
        if(i<=0){
            if(s[0]=='0')return 0;
            else return 1;
        }
        
        if(dp[i]!=-1) return dp[i]; //if value of dp[i] has been calculated previously, it is reused
        
        int single = 0; //this variable stores the count of ways possible when the last one digit of the string is decoded at a time
        if(s[i]!='0') single = f(i-1, s, dp);
        
        int dbl = 0; //this variable stores the count of ways possible when the last two digits of the string are decoded at a time
        if(i>=1 && s[i-1]!='0'){
            string temp = "";
            temp += s[i-1];
            temp += s[i];
            if(stoi(temp)<=26) dbl = f(i-2, s, dp);
        }
        
        return dp[i]= single + dbl; //dp[i] stores the number of ways a string of length i can be decoded
    }
        
public:
    
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n, -1); //vector being used for memoization
        return f(n-1, s, dp);
    }
};