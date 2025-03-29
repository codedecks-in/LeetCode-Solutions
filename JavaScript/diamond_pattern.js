const diamondPattern = (n) => {
   let iteration = 0;
   const construct = ['*'.repeat(2 * n - 1)];
   n *= 2;
   while ((n -= 2) > 0) {
      const layer = ' '.repeat(++iteration) + '*'.repeat(n - 1);
      construct.unshift(layer); 
      construct.push(layer);   
   }
   construct.forEach((pattern) => console.log(pattern)); 
}

diamondPattern(5);
