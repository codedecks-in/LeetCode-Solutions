"use strict";

let N = 3;

function rotate90Clockwise(arr) {
  for (let j = 0; j < N; j++) {
    for (let i = N - 1; i >= 0; i--) {
      process.stdout.write(arr[i][j] + " ");
    }
    console.log();
  }
}

let arr = [
  [1, 1, 1],
  [2, 2, 2],
  [3, 3, 3],
];

console.log("Initial matrix:");
for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    process.stdout.write(arr[i][j] + " ");
  }
  console.log();
}

console.log("\nRotated matrix:");
rotate90Clockwise(arr);
