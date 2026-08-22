let mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];

function adjoint(matrix) {
let A00 = matrix[0][0];
let A01 = matrix[0][1];
let A02 = matrix[0][2];
let A10 = matrix[1][0];
let A11 = matrix[1][1];
let A12 = matrix[1][2];
let A20 = matrix[2][0];
let A21 = matrix[2][1];
let A22 = matrix[2][2];

let adj = [[(A11 * A22 - A12 * A21), -(A01 * A22 - A02 * A21), (A01 * A12 - A02 * A11)],
[-(A10 * A22 - A12 * A20), (A00 * A22 - A02 * A20), -(A00 * A12 - A02 * A10)],
[(A10 * A21 - A11 * A20), -(A00 * A21 - A01 * A20), (A00 * A11 - A01 * A10)]];
return adj;
}

let adjaointOfMatrix = adjoint(mat)
console.log(adjaointOfMatrix)
