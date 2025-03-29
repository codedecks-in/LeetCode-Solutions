const powerOfNumber = (num, power) => {
  if (power < 0 || num < 0) {
    return "Invalid Input";
  } else if (power == 0) {
    return 1;
  } else {
    return Math.pow(num, power);
  }
};

console.log(powerOfNumber(2, 3));
console.log(powerOfNumber(2, 0));
console.log(powerOfNumber(2, -3));
