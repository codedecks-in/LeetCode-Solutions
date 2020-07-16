/**
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2
**/
class Solution {
    public int firstUniqChar(String s) {
        
        HashMap<Character, Integer> map = new LinkedHashMap<>();
        
        for(int i=0;i<s.length(); i++){
            Character ch = s.charAt(i);
            
            if(map.containsKey(ch)){
                int value = map.get(ch);
                map.put(ch, value+1);
            }
            else{
                map.put(ch, 1);
            }
        }
        
        char firstNonRepeatChar = ' '; // dummyValue
        
        for(Map.Entry<Character, Integer> entry : map.entrySet()){
            if(entry.getValue() == 1){
                firstNonRepeatChar = entry.getKey();
                break;
            }
        }
        
        for(int i=0;i<s.length(); i++){
            if(s.charAt(i) == firstNonRepeatChar){
                return i;
            }
        }
        
        return -1;
    }
}
