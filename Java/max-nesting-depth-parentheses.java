class Solution {
    public int maxDepth(String s) {
        
        int maxDepth = Integer.MIN_VALUE;
        int depth = 0;
        
        for(int i=0; i<s.length(); i++){
            
            if(s.charAt(i) == '('){
                depth++;
            }
            else if(s.charAt(i) == ')'){
                depth--;
            }
            maxDepth = (depth > maxDepth) ? depth : maxDepth;
        }
        
        return maxDepth;
    }
}
