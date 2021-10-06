//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

public int findNumbers(int[] nums) {
    int count = 0;
   for (int i = 0; i < nums.length ; i++) {
       String s = Integer.toString(nums[i]);;
       int l = s.length();

       if( l % 2 == 0)
           count++;

   }

   return  count;
}