const getCube = (n) => n * n * n;

const checkArmstrongNumber = (number) => {
  if (typeof number !== "number") return "Please enter a valid number.";

  const digitsOfNUmber = String(number)
    .split("")
    .map((digit) => Number(digit));

  let sumOfCubesOfDigits = 0;

  digitsOfNUmber.forEach((digit) => {
    sumOfCubesOfDigits += getCube(digit);
  });

  const isArmstrong = sumOfCubesOfDigits === number;

  return isArmstrong ? "Armstrong Number" : "Not Armstrong Number";
};

console.log(checkArmstrongNumber(153));
