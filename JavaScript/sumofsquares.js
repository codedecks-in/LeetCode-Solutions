let input = [1,2,3,4,5];

let sumOfSquaresOfNumbers = 0;

for(let i = 0; i<input.length;i++)
{
    sumOfSquaresOfNumbers = sumOfSquaresOfNumbers + Math.pow(input[i],2);
}

console.log(sumOfSquaresOfNumbers);
