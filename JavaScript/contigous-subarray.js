function maximumContiguousSum(arr){
    let sum = 0;
    let i = 0;
    let maxsum = -Infinity;
    while(i<arr.length){
        sum += arr[i];
        maxsum = Math.max(maxsum,sum);
        if(sum < 0){
            sum = 0;
        }
        i++;
    }
    return maxsum;
}

let arr = [-2, -3, 4, -1, -2, 1, 5, -3];
console.log(maximumContiguousSum(arr));
