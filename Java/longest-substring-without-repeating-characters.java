    
class Solution {   
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        
        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        
        int l=0;
        int r=0;
        int max = Integer.MIN_VALUE;
        
        while(r<s.length()){
            char c = s.charAt(r);
            if(!set.contains(c)){
                set.add(c);
                max = Math.max(max, set.size());
                ++r;
            } else {
                set.remove(s.charAt(l));
                ++l;
            }
        }
        
        return max;
    }
}