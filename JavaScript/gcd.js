function gcd(a,b)
{
    let result = Math.min(a, b); 
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }return result; 
}

let a = 10;
let b = 5;
console.log("GCD of ",a," and ",b," is ",gcd(a, b));
