#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        if(n == 1)
        {
            cout<<2<<endl;
            continue;
        }
        n--;
        vector<pair<long long int,long long int>> dp(n+1);
        dp[1] = {1,1};
        for(long long int i=2;i<=n;i++)
        {
            dp[i] = {((4*dp[i - 1].first) + dp[i - 1].second),(dp[i - 1].first + (2 * dp[i - 1].second))};
            dp[i].first = dp[i].first%1000000007;
            dp[i].second = dp[i].second%1000000007;
        }
        cout<<((5 * dp[n].first) + (3 * dp[n].second))%1000000007<<endl;
    }
    return 0;
}