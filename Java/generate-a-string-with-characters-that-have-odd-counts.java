class Solution {
    public String generateTheString(int n) {
        String result = "";
        if(n % 2 == 0) {
            for(int i = 1; i <= n - 1; i++) {
                result = result + 'x';
            }
            
            result = result + 'y';
        }
        else {
            for (int i = 1; i <= n; i++)
            {
                result = result + 'x';
            }
        }
        
        return result;
    }
    
}