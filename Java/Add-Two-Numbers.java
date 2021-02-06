/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 *
 * Runtime: 67 ms
 * Memory Usage: 53.9 MB
 *
 */
import java.math.BigInteger;

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode currHead1 = l1;
        BigInteger list1 = BigInteger.valueOf(0);
        BigInteger x = BigInteger.valueOf(1);
        String s;
        
        while(currHead1 != null){
            s = "" + (x.multiply(BigInteger.valueOf(currHead1.val)));
            list1 = list1.add(new BigInteger(s));
            currHead1 = currHead1.next;
            x=x.multiply(BigInteger.valueOf(10));
        }
        //System.out.println(list1);
        
        x = new BigInteger("1");
        ListNode currHead2 = l2;
        BigInteger list2 = BigInteger.valueOf(0);
        
        while(currHead2 != null){
            s = "" + (x.multiply(BigInteger.valueOf(currHead2.val)));
            list2 = list2.add(new BigInteger(s));
            currHead2 = currHead2.next;
            x=x.multiply(BigInteger.valueOf(10));
        }
        //System.out.println(list2);
        list2 = list2.add(list1);
        
        //System.out.println(list2);
        StringBuffer sb = new StringBuffer(""+list2+"");
        sb.reverse();
        //System.out.println(sb.toString());
        String str = sb.toString();
        
        ListNode result = new ListNode(Integer.parseInt(str.charAt(0)+""));
        ListNode head = result;
        
        for(int i=1;i<str.length();i++){
            head.next = new ListNode(Integer.parseInt(str.charAt(i)+""));
            //System.out.println(head.next.val);
            head = head.next;
        }
        
        return result;
    }
}
