/*
                                                    #Hacktoberfest2021
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.


Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)


Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.


Example 4:

Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000
*/
class Solution {
public:
    int maxSatisfaction(vector<int>& st) {
        
        sort(st.begin(),st.end());
        
        int n = st.size();
        int sum = 0;
        
        for(int i=0;i<n;i++)
            sum+=st[i];
        
        int i=0;
        
        if(sum<0) {
            //int i=0;
            while(sum<0) {
                sum = sum-st[i++];
            }
            
        }
        
        int t = 1,ans = 0;
        
        for(int k=i;k<n;k++) {
            ans+=(st[k]*t);
            t++;
        }
        
        return ans;
        
        
        
    }
};