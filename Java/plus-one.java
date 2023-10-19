class Solution {
    public int[] plusOne(int[] digits) {
        int length = digits.length;
        
        // if number does not consist of only 9s, increment the last digit in the array by 1.
        for (int i = length-1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // If number consists of only 9s, reassign all the digits to be 0 
            digits[i] = 0;
        }   
        // Create a new array that is larger by 1 (with all digits as 0 by default). 
        digits = new int[length + 1];
        // Set the first digit as 1.
        digits[0] = 1;
        return digits;
    }
}