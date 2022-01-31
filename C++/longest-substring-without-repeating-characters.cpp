class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 0, count = 0, start = 0;
        unordered_map<char, int> used;

        for(unsigned int i = 0; i < s.length(); i++)
        {
            if(count > max)
            {
                max = count;
            }

            if(used.find(s[i]) == used.end())
            {
                used.emplace(s[i], i);
                count++;
            }
            else
            {
                if(used[s[i]] < start)
                {
                    used[s[i]] = i;
                    count++;
                }
                else
                {
                    start = used[s[i]] + 1;
                    count = i - used[s[i]];
                    used[s[i]] = i;
                }
            }
        }

        if(count > max)
        {
            max = count;
        }

        return max;
    }
};
