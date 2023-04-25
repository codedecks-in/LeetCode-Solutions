    
class Solution {   
    public int lengthOfLongestSubstring(String s) {
        //Use set because we are concerned with checking for repeating chars
        Set<Character> set = new HashSet<>();
        
        //Base cases
        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        
        //Sliding window approach
        int l=0;
        int r=0;
        int max = Integer.MIN_VALUE;
        
        while(r<s.length()){
            //Get current char in the string
            char c = s.charAt(r);

            //If set doesn't contain character, we keep expanding window forward and 
            //update max length of substring
            if(!set.contains(c)){
                set.add(c);
                max = Math.max(max, set.size());
                ++r;
            
            //If repeating character found, move left window forward
            //and remove any duplicate characters along the way
            } else {
                set.remove(s.charAt(l));
                ++l;
            }
        }
        
        //Return the max length substring
        return max;
    }
}