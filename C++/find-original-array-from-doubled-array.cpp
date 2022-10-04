class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans, fail;
        unordered_map <int, int> umap;
        for (int i=0;i<changed.size();i++){
            umap[changed[i]]++;
        }
        if (changed.size()%2) return fail;
        sort(changed.begin(),changed.end());
        
        for (int i=0;i<changed.size();i++){
            if (umap[changed[i]]){
                if (umap[changed[i]*2]){
                    ans.push_back(changed[i]);
                    umap[changed[i]*2]--;
                    umap[changed[i]]--;                    
                }
                else return fail;
            }
        }
        return ans;
    }
};
