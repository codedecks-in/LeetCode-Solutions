class Solution {
    public boolean isPalindrome(int x) {
        String _x = x+""; // integer convert string
        String rev = ""; // store reverse
        int i = 0;
        for(i = _x.length()-1; i>=0; i--){
            rev += _x.charAt(i); 
        }
        
        if(_x.compareTo(rev) == 0){
            // correct
            return true;
        }
        else{
            return false;
        }
        
    }
}
