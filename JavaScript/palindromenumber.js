function checkPalindromeNumber(num) {
    let remainder, temp, reversedNumber = 0;
    temp = num;
    while (num > 0) {
        remainder = num % 10;
        num = Math.floor(num / 10);
        reversedNumber = reversedNumber * 10 + remainder;
    }
    return reversedNumber === temp;
}
console.log(checkPalindromeNumber(190));
