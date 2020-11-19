class HappyNumber {
    public boolean isHappy(int n) {
        int num1, num2; 
   
    num1 = num2 = n; 
    do
    { 
        num1 = SquareSum(num1); 
   
         
        num2 = SquareSum(SquareSum(num2)); 
   
    } 
    while (num1 != num2); 
   
    return (num1 == 1); 
} 


static int SquareSum(int n) 
    { 
        int square = 0; 
        while (n!= 0) 
        { 
            square += (n % 10) * (n % 10); 
            n /= 10; 
        } 
    return square; 
    } 
 
}
