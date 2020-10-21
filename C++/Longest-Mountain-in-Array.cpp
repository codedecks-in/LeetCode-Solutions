/*
Difficulty: medium
runtime: 36ms
*/
/*
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)
Given an array A of integers, return the length of the longest mountain. Return 0 if there is no mountain.

Note:
0 <= A.length <= 10000
0 <= A[i] <= 10000

Example 1:
  Input: [2,1,4,7,3,2,5]
  Output: 5
  Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:
  Input: [2,2,2]
  Output: 0
  Explanation: There is no mountain.

Followup:
Can you solve it using only one pass? YES
Can you solve it in O(1) space? YES
___________________________________________________________________________________________________________________________
CodeExplain:
  while treversing the array..we have to just count increasing and decreasing numbers.
  and maximize the addition of increasing and decreasing numbers.

*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return 0;
        int ans = 0, left = 0, right = 0;// left = increasing, right = decreasing
        for(int i=1;i<n;i++)
        {
            if(A[i]>A[i-1]){ //increasing count
                if(right){
                    left=0;
                    right=0;
                }
                left += (1 + (left==0));
            }
            else if(A[i]<A[i-1] && left) //right = decreasing count
                right += 1;
            else{ //same numbers
                left=0;
                right=0;
            }

            ans = max((left + right) * (left && right), ans); //maximize the ans
        }
        return ans;
    }
};
