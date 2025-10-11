class Solution {
    
public:
    static bool cmp(string a, string b){
        //if(a+b == b+a) return a>b;
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        string res = "";
        for(int i : nums) s.push_back(to_string(i));
        sort(s.begin(), s.end(), cmp);
        for(int i=0; i<s.size(); i++){
            res += s[i];
            //if(s[i] == "0") return 0;
        }
        if(res[0] == '0') return "0";
        return res;
    }
};
