let FindLcmOfTwoNumbers = (n1, n2) => {
    let lar = Math.max(n1, n2);
    let small = Math.min(n1, n2);

    let i = lar;

    while(i % small !== 0){
        i += lar;
    }

    return i;
}

const n1 = 12;
const n2 = 18;
console.log('Inputs  :', n1, n2);
console.log('Output :', FindLcmOfTwoNumbers(n1, n2));
