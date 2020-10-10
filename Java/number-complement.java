class Solution {
    public int findComplement(int num) {
        
        int numberOfBits = numberOfBits(num);
        
        return num ^ ((1 << numberOfBits) - 1);
    }
    
    /**
    * Method to find out the total number of bits in a number.
    **/
    public static int numberOfBits(int num){
        int countOfBits = 0;
        
        while(num != 0){
            num = num >> 1;
            countOfBits++;
        }
        
        return countOfBits;
    }
}
