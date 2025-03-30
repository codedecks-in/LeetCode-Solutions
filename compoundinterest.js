function calculateCompoundInterest(principal, rate, time) {
  const compoundFactor = 1 + rate / 100;

  const compoundInterest = principal * Math.pow(compoundFactor, time);
  return compoundInterest;
}
console.log(calculateCompoundInterest(1000, 10, 5));
