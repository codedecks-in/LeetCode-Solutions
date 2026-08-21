class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> mpp;
        
        for(int i=0;i<strs.size();++i){
            string tmp=strs[i]; 
            sort(tmp.begin(), tmp.end());
            mpp[tmp].push_back(i);
        }
        
        vector<vector<string>> ans(mpp.size());
        int i=0;
        for(auto z: mpp){
            for(auto x: z.second){
                ans[i].push_back(strs[x]);
            }
            i++;
        }
        return ans;
    }
};
