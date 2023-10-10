//2897. Apply Operations on Array to Maximize Sum of Squares

class Solution {
public:
    const unsigned mod=1e9+7;
    void print(vector<int>& nums){
        for(int x: nums)
            cout<<x<<",";
        cout<<endl;
    }
    int maxSum(vector<int>& nums, int k) {
        vector<int> Bit(31, 0);
        for(int x: nums){
            #pragma unroll
            for(int b=0; b<31; b++)
                Bit[b]+=((x>>b)& 1);
        }
        unsigned long long ans=0;
        #pragma unroll
        for(int i=0; i<k; i++){
            long long x=0;
            for(int b=0; b<31; b++){
                if (Bit[b]-->0){
                    x+=(1<<b);
                }
            }
            ans=(ans+x*x)%mod;
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
