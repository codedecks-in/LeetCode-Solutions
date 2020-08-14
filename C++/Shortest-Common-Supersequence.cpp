/*
 *
 * Runtime : 12ms, faster than 98.40% 
 * Memory  : 10.7MB, faster than 85.57%
 * prerequisite : least common subsequence in string	
 */
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int i = str1.length();
        int j = str2.length();
        
        
        
        int t[i+1][j+1];
        
	// create matrix of size str1 length as row
	// and str2 length as column 

	// base condition
        for(int k = 0;k<=i;k++)
        {
            t[k][0] = 0;
        }
        
	// base condition
        for(int k = 0;k<=j;k++)
        {
            t[0][k] = 0;
        }
        
	// to form different solution from all possible length string
        for(int k = 1;k<=i;k++)
            {
                for(int l = 1;l<=j;l++)
                    {   
                        if(str1[k-1] == str2[l-1])
                        {
                            t[k][l] = 1+t[k-1][l-1];
                        }
                        else{
                            t[k][l] = max(t[k-1][l],t[k][l-1]);
                        }
                    }
            }
            
        string res="";
        
        while(i>0 && j>0)
        {
	    // if char are same in str1 and str2, add it one time
            if(str1[i-1]==str2[j-1])
            {
                res.push_back(str1[i-1]);  
                i--;j--;
            }
            else{
		
		// comparing matrix value to form string
		// add both characters of string to answer
                if(t[i][j-1] > t[i-1][j])
                {
                    res.push_back(str2[j-1]);
                    j--;
                }
                else{
                    res.push_back(str1[i-1]);
                    i--;
                }
                
            }
        }
        
        while(i>0)
        {
            res.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            res.push_back(str2[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
