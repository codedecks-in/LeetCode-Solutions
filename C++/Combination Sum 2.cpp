class Solution {
public:
    
    set<vector<int>> ans;  //taking set becoz we don't want to repeat the vectors
    
    void fun(vector<int> v, vector<int> temp, int target, int ind){
        if(target==0){
            ans.insert(temp);
            return;
        }
        if(ind==v.size()){
            if(target==0){
                ans.insert(temp);
            }
            return;
        }
        //If we take the current element/ if pick
        if(v[ind]<=target){
            temp.push_back(v[ind]);
            fun(v, temp, target-v[ind], ind+1);
            temp.pop_back();
        }
        //If not pick
        fun(v, temp, target, ind+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        int s=0;
        for(auto z: cand){
            s+=z;
        }
        vector<vector<int>> tot;
        if(s<target) return tot;
        
        if(s==target){
            tot.push_back(cand);
            return tot;
        }
        int n=cand.size();
        
        vector<int> temp;
        fun(cand, temp, target, 0);
        
        cout<<ans.size()<<endl;
        
        
        for(auto z: ans){
            tot.push_back(z);
        }
        return tot;
    }
};
