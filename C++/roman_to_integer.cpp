/* difficulty level : Easy
Codechef problem link:  https://leetcode.com/problems/roman-to-integer/
TC=O(n),SC=O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        
        int ans=0,i,l,num;
        l=s.size();
        for(i=l-1;i>=0;i--)
        {
            switch(s[i])
            {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            if(4*num<ans)
            {
                ans-=num;
            }
            else
                ans+=num;
        }
        return ans;
    }
};
