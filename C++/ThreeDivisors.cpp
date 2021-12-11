class Solution {
public:
    
    bool isPrime(int n){ // Time Complexity = O(Sqrt(N))
        if(n==2||n==3) 
            return true;
        if(n%2==0||n%3==0)
            return false;
        for(int i = 5;(i*i)<=n;i+=5){ 
        if(n%i ==0 || n%(i+2) == 0){
            return false;
            break;
        }
        }
        return true;
    }
    
    bool isThree(int n) {
        
    if(n<3) 
        return false; 
        
    long double sqr = sqrt(n);   // Computing Square root of number which return double.
	 
	 // Checking if the number is a square of a prime number. 
	 // And the square root of number is a perfect whole number. 
	 /* Example: Suitable for test case: sqrt(12) =3.4641 so if converted into int it will automatically be equal to 3.
	  Thus explicitly checking if 3.4641 == 3 (false) so wont enter this case.
	  Sqrt(49) = 7.0 = 7 (true) will satisfy the condition.
	  */
    if((int)sqr == sqr && isPrime(sqr))   
        return true;
    else 
        return false;
        
    }
};