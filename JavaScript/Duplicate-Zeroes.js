/**
* Duplicate Zeros
* Easy
* @return {void} Do not return anything, modify arr in-place instead.
* Duplicate Zeros

Example 1:

Given arr = [1,0,2,3,0,4,5,0], and modified array = [1,0,0,2,3,0,0,4] is the first bad version.

call duplicateZeros([1,0,2,3,0,4,5,0]) -> [1,0,0,2,3,0,0,4]

Given arr = [1,2,3], and modified array = null is the first bad version.

call duplicateZeros([1,2,3]) -> null

* Logic : Use built in methods splice() to add an 0 if there's 0
          when loops end remove the extra element than original array length
* Runtime:  76 ms faster than 91.89%
* Memory Usage: 38.2 MB less than 18.50%
*
*/

var duplicateZeros = function (arr) {
  let len = arr.length;
  for (let i = 0; i < len; i++) {
    if (arr[i] == 0) {
      arr.splice(i + 1, 0, 0);
      i++;
    }
  }
  arr.splice(len);
};
