//Expected Time Complexity: O(N)

#include <bits/stdc++.h>

using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int>breaking1;
        int cnt_1=0;
        int max=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                cnt_1++;
            }
            if(nums[i+1]==0)
            {
                breaking1.push_back(cnt_1);
                if(max<cnt_1)
                {
                    max=cnt_1;
                    // cout<<max<<endl;
                }
                cnt_1=0;
            }
        }
        
        int maxofmax=breaking1[0];
        for(int i=0;i<breaking1.size();i++)
        {
            if(maxofmax<breaking1[i])
            {
                maxofmax=breaking1[i];
            }
        }
        return maxofmax;
        
        
    }
int main()
{
    vector<int>nums={1,1,0,1,1,1,1,1,1};
    int temp=findMaxConsecutiveOnes(nums);
    cout<<"\nans: "<<temp;
    return 0;
}
