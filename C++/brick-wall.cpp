//done using hash table
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size(),i,j,pos,maxcount=0;
        
        unordered_map<int,int> m;
        unordered_map<int,int>:: iterator it;
        
        for(i=0;i<n;i++)
        {
            pos=0;
            for(j=0;j<wall[i].size()-1;j++)
            {
                pos+=wall[i][j];
                
                m[pos]++;
                //maxcount=max(maxcount,m[pos]);
            }
        }
        
        for(it= m.begin();it!=m.end();it++)
        {
            maxcount=max(maxcount,it->second);
        }
        return (n-maxcount);
    }
};
