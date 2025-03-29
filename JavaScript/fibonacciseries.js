function getFiboNumber(n){
    if(n <= 1){
        return n;
    } else {
        return getFiboNumber(n-1) + getFiboNumber(n-2);
    }
}

let input = 5;
let output = '';
for(let i=0; i < input; i++){
    output = output + " " + getFiboNumber(i);
}
console.log(output);
