// C++ Program to fing the string witth minimum window substring

#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
       
         if (s.size() == 0 || t.size() == 0) 
             return "";
        
        vector<int> remaining(128, 0);
        int required = t.size();
        
        for (int i = 0; i < required; i++) 
            remaining[t[i]]++;
        
        int min = INT_MAX, start = 0, left = 0, i = 0;
        
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0) required++;
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
        
  }
  

int main()
{
	string s,t;
    cin>>s>>t;

    cout<<minWindow(s,t)<<endl;

    // for example:-
    // Input: s = "ADOBECODEBANC", t = "ABC"
    // Output: "BANC"

    // Input: s = "a", t = "aa"
    // Output: ""

	return 0;
}
