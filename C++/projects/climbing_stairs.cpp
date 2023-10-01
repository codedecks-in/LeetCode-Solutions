#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        // dp[i] here represents the state that symbolizes that the no of ways to arrive at ith staircase
        // that is the from one step back and two step back sum
        dp[i]=dp[i-1]+dp[i-2];// that is no of ways we can achieve from taking one step or two step
    }
    return dp[n];
}
    
int main(){
    int n;
    cin>>n;
    cout<< climbStairs(n);
	return 0;
}
