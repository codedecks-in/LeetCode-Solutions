/**
    Medium: 
    
    Given an integer n, return the number of prime numbers that are strictly less than n.

    Example 1:
    Input: n = 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    Example 2:
    Input: n = 0
    Output: 0

    Example 3:
    Input: n = 1
    Output: 0
    

    Constraints:
    0 <= n <= 5 * 106
*/

/**
 * Runtime: 440 ms
 * Memory Usage: 79.6 MB 
 * 
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    if(n < 2){
        return 0;
    }
    
    let isPrime = Array(n).fill(true);
    
    // Assume everything is prime & when you find a prime number, set all multiples of it to not prime
    for(let i = 2; i * i < n; i++){
        if(isPrime[i]){
            for(let j = i; j * i < n; j++){
                isPrime[i*j] = false;
            }
        }
    }
    
    const primeCount = isPrime.reduce((accum, curr) => curr ? accum + 1 : accum, 0);
    
    return primeCount - 2; // exclude 0, 1
};