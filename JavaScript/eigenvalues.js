import { eigs, round } from "mathjs";

const matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];

const { values } = eigs(matrix);
const eigenvalues = values.map() (
  round(num, 15)
);

console.log(eigenvalues); 
