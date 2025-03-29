/*
- Longest Substring Without Repeating Characters -
Difficultly: Medium
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        //creates vars to store overall maximum length, current length, and index of current sequence
	int max = 0, count = 0, start = 0;
        //creates unordered_map to store the chars used and the index of the chars used in the string
	unordered_map<char, int> used;

	//loops through each char in string
        for(unsigned int i = 0; i < s.length(); i++)
        {
            //reassigns max length if current length exceeds
	    if(count > max)
            {
                max = count;
            }

	    //if current char has not been used yet
            if(used.find(s[i]) == used.end())
            {
		//add char to map and increase count
                used.emplace(s[i], i);
                count++;
            }
            else
            {
		//checks if prev occurence of char is before current sequence
                if(used[s[i]] < start)
                {
                    //updates the index to the current index for future use and increase count
		    used[s[i]] = i;
                    count++;
                }
                else
                {
                    //resets starting index to next index in the string
		    start = used[s[i]] + 1;
		    //resets count to the difference between the current index and the prev occurrence of the char's index
                    count = i - used[s[i]];
		    //updates the index to the current index for future use
                    used[s[i]] = i;
                }
            }
        }

	//performs one last check to ensure the last substring wasn't larger than the maximum
        if(count > max)
        {
            max = count;
        }

        return max;
    }
};
