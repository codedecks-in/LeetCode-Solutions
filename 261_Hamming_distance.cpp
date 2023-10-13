class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int i,j,k,num,count=0;
        int sum=0;
        vector<int>result;
        sum=x^y;
        while(sum>0)
        {
            num=sum%2;
            if(num==1)
            {
                count++;
            }
            sum=sum/2;
        }
        return count;
        
    }
};
