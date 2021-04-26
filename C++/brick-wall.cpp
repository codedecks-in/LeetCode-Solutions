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

Reduced Code for the given problem that reduces one for loop and also has less auxiliary space!

// Time:  O(n), n is the total number of the bricks
// Space: O(m), m is the total number different widths

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> widths;
        auto result = wall.size();
        for (const auto& row : wall) {
            for (auto i = 0, width = 0; i < row.size() - 1; ++i) {
                result = min(result, wall.size() - (++widths[width += row[i]]));
            }
        }
        return result;
    }
};