class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long int n = nums.size();
        // first find the next greatest element to the right
        // here, we need to find elem>nums[i] to the right
        vector<long long int>next_greatest_right(n, n);
        stack<long long int>s; // stores indexes
        for(long long int i=0;i<n;i++)
        {
            if(s.size()==0 || nums[s.top()]>=nums[i])
            {
                s.push(i);
            }
            else
            {
                while(s.size() && nums[i]>nums[s.top()])
                {
                    next_greatest_right[s.top()]=i;
                    s.pop();
                }
                s.push(i);
            }
        }
         // then find the next greatest element to the left
        // here, we we need to find elem >=nums[i] to the left
        // because, there may be duplicates, so to account for them to count only once, we are using > for right side and >= for left side
        
        // test it with the case of [1,3,3,4] or [1,3,4,3,2]
        vector<long long int>next_greatest_left(n,-1);
        while(s.size()) s.pop();
        for(long long int i=n-1;i>=0;i--)
        {
            if(s.size()==0 || nums[s.top()]>nums[i])
            {
                s.push(i);
            }
            else
            {
                while(s.size() && nums[i]>=nums[s.top()])
                {
                    next_greatest_left[s.top()]=i;
                    s.pop();
                }
                s.push(i);
            }
        }
        // for(long long int i=0;i<n;i++) cout<<next_greatest_left[i]<<" ";
        
        long long int maxi_sum=0;
        for(long long int i=0;i<n;i++)
        {
            long long int l = next_greatest_left[i];
            long long int r = next_greatest_right[i];
            maxi_sum+=(nums[i]*(i-l)*(r-i));
        }
        // cout<<maxi_sum<<endl;
        
        // Now finding next smallest element to the right and left like how we did for next greatet element
        vector<long long int>next_smallest_right(n,n);
        while(s.size()) s.pop();
        for(long long int i=0;i<n;i++)
        {
           if(s.size()==0 || nums[s.top()]<=nums[i])
            {
                s.push(i);
            }
            else
            {
                while(s.size() && nums[i]<nums[s.top()])
                {
                    next_smallest_right[s.top()]=i;
                    s.pop();
                }
                s.push(i);
            }
        }
        
        vector<long long int>next_smallest_left(n,-1);
        while(s.size()) s.pop();
        for(long long int i=n-1;i>=0;i--)
        {
            if(s.size()==0 || nums[s.top()]<nums[i])
            {
                s.push(i);
            }
            else
            {
                while(s.size() && nums[i]<=nums[s.top()])
                {
                    next_smallest_left[s.top()]=i;
                    s.pop();
                }
                s.push(i);
            }
        }
        
        long long int mini_sum=0;
        for(long long int i=0;i<n;i++)
        {
            long long int l = next_smallest_left[i];
            long long int r = next_smallest_right[i];
            mini_sum+=(nums[i]*(i-l)*(r-i));
        }
        // cout<<mini_sum<<endl;
        return maxi_sum-mini_sum;
        
    }
};
