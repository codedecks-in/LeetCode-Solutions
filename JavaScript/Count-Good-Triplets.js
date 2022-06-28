/**
1534. Count Good Triplets
Brute Force Solution
 */

/**
 * @param {number[]} arr
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */

var countGoodTriplets = function (arr, a, b, c) {
  let triplet_count = 0;

  // for each i, for each j, check if the first condition is satisfied
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      if (Math.abs(arr[i] - arr[j]) <= a) {
        // for each k, check if the last two conditions are satisfied
        for (let k = j + 1; k < arr.length; k++) {
          if (
            Math.abs(arr[j] - arr[k]) <= b &&
            Math.abs(arr[i] - arr[k]) <= c
          ) {
            // all the conditions are satisfied, increase the count by one!
            triplet_count++;
          }
        }
      }
    }
  }

  return triplet_count;
};
