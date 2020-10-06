// A simple cpp solution using maps and set 

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        map<int,int> m;
        set<pair<int,int>> sp;
        
        // create a map storing all the frequencies
        for(int i:nums) m[i]++;
        
        int ans=0;
        for(auto i:m){

            // if k = 0, add one entry to the set if freq > 1
            if(k==0 && m[i.first]>1){
                sp.insert({i.first,i.first});
            }
            else if(k!=0 && m.find(i.first+k)!=m.end()){
                sp.insert({i.first,i.second});
            }
        }

        // answer is the number of elements in the set
        return sp.size();
    }
};