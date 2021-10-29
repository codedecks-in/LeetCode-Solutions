class Solution {
    public int[] plusOne(int[] digits) {
        int length = digits.length;
        
        for (int i = length-1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }   
        digits = new int[length + 1];
        digits[0] = 1;
        return digits;
    }
}