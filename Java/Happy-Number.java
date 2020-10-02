class Solution {
    public boolean isHappy(int n) {
        
        Set<Integer> unique = new HashSet<Integer>();

        while (unique.add(n))
        {
            int value = 0;
            while (n > 0)
            {
                value += Math.pow(n % 10, 2);
                n = n/10;
            }
            n = value;
        }

         
        if(n == 1)
            return true;
        else
            return false;
        
   }
}