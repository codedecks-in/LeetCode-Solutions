/** 
 *  Problem Name : Buddy Strings
 *  Concept Involved : String Manipulation, Frequency Computation, Observation
 * 
 *  Execution Time : 2 ms
 *  Memory Consumed : 39.1 mb
 * 
*/
class Solution {
    public boolean isDuplicate(String str){
        int[] fre = new int[26];
        for(int i=0; i<str.length(); i++){
            int ind = str.charAt(i) - 'a';
            fre[ind]++;
            if(fre[ind] > 1){
                return true;
            }
        }
        return false;
    }
    public boolean buddyStrings(String A, String B) {
        if(A.length() != B.length()){
            return false;
        }
        
        int count = 0;
        char ca = 'A';
        char cb = 'A';
        
        for(int i=0; i<A.length(); i++){
            if(A.charAt(i) != B.charAt(i) ){
                if(count == 0){
                    ca = A.charAt(i);
                    cb = B.charAt(i);
                }
                else if(count == 1){
                    if(ca != B.charAt(i) || cb != A.charAt(i)){
                        count++;
                    }
                }
                count++;
            }
        }
        
        if(count == 2 || (count == 0 && isDuplicate(A))){
            return true;
        }
        return false;
    }
}
