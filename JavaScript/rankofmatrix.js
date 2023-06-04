function getRank(matrix) {
  let m = matrix.length;
  let n = matrix[0].length;
  let rank = Math.min(m,n);
  let pivot;
  
  for(let i=0; i<rank; i++) {
    pivot = matrix[i][i];
    
    if(pivot = 0) {
      for(let j= i+1; j<m; j++) {
        if(matrix[j][i] != 0) {
          let temp = matrix[i];
          matrix[i] = matrix[j];
          matrix[j] = temp;
          pivot = matrix[i][i];
          break;
        }
      }
    }
    
    if(pivot === 0) {
      rank--;
      continue;
    }
    
    for(let j=i; j<n; j++) {
      matrix[i][j] /= pivot;
    }
    
    for(let j=0; j<m; j++) {
      if(j !== i) {
        let factor = matrix[j][i];
        for(let k=i; k<n; k++) {
          matrix[j][k] -= factor * matrix[i][k];
        }
      }
    }
  }  
  
  return rank;
}

console.log(getRank([[1,2,3], [4,5,6], [7,8,9]]));
