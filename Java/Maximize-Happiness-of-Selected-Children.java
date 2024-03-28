/** 
 *  Problem Name : Maximize Happiness of Selected Children
 *  Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/
 *  Concept Involved : Array, Greedy, Sorting
 * 
 *  Execution Time : 34 ms
 *  Memory Consumed : 61.37 mb
 * 
*/

/*
 *  Approach: Think of a greedy approach. Select the children who give maximum happiness at each step
 */

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        long res = 0;
        // Sorting the array in ascending order. 
        Arrays.sort(happiness);
        // Iterating from the end of the array and adding the maximum happiness of the k children.
        for(int i = happiness.length - 1; i >= happiness.length - k ;i--){
            // Adding the maximum happiness of the k children. Handling the case that happiness cant be negative.
            res += Math.max(happiness[i] - (happiness.length - 1 - i), 0);
        }
        return res;
    }
}