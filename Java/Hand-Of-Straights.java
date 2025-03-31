package testing;

/*Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.
*/

/*Runtime: 51 ms
Memory Usage: 41.4 MB
Difficulty Medium
*/
import java.util.PriorityQueue;

public class HandOfStraights {

    public boolean isNStraightHand(int[] hand, int W) {
     PriorityQueue<Integer> pQueue=new PriorityQueue<Integer>();
        for(int i=0;i<hand.length;i++){
            pQueue.add(hand[i]);
        }
        while(pQueue.size()!=0){
            int small=pQueue.peek();
            for(int i=0;i<W;i++){
                if(!pQueue.contains(small+i)){
                    return false;
                }else{
                    pQueue.remove(small+i);
                }
            }
        }
        return true;
    }
}
