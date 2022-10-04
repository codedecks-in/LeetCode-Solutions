const isPalindrome = function(x) {
    const str = x.toString()
    const reverse = str.split('').reverse().join('');

    if(x == reverse) return true;
    
    return false;
};