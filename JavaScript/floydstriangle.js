let printFloydsTriangle = (num) => {
  let count = 1;

  for (let i = 1; i <= num; i++) {
    let str = "";

    for (let j = 1; j <= i; j++) {
      str = str + count + " ";
      count++;
    }
    console.log(str.trim());
  }
};

printFloydsTriangle(5);
