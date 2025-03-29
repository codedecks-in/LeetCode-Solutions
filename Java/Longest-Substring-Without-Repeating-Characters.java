class Solution {
    public int lengthOfLongestSubstring(String s) {
    
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    
        int left = 0;
        int right = 0;
        int n = s.length();
        int len = 0;
        
        while (right<n) {
            
            if (map.containsKey(s.charAt(right))){
                left = Math.max(map.get(s.charAt(right))+1, left);
            }
            map.put(s.charAt(right), right);
            len = Math.max(len, right-left+1);
            right++;
        }
        return len;
    }
}