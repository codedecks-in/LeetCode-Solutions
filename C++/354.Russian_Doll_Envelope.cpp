/*
    This code uses Dynamic Programming Approach to evaluate the answer.
    We need to sort the array on width and to perform LIS on height.

    Time Complexity  : O(N^2)
    Space Complexity : O(N)
*/


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>>v1(envelopes.size());
        for(int i=0;i<envelopes.size();i++)
        {
            v1[i]=make_pair(envelopes[i][0],envelopes[i][1]);
        }
        
        sort(v1.begin(),v1.end());

        vector<int> dp(envelopes.size(),1);
        dp[0]=1;
        for(int i=1;i<envelopes.size();i++){
            int ans=INT_MIN;
            for(int j=i-1;j>=0;j--){
                if(v1[j].second<v1[i].second&&v1[j].first!=v1[i].first){
                    ans=max(ans,dp[j]);
                }
            }
            if(ans!=INT_MIN){
                dp[i]=ans+1;
            }
        }

        return *max_element(dp.begin(),dp.end());
    }
};