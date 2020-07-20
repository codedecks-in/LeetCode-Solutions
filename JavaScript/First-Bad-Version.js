/**
* First Bad Version
* Easy
* 
* Find The First Bad Version

Example 1:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 

* Logic : Using binary search to find the first bad version.
  if mid - 1 is not a bad version then mid is first bad version
  if mid - 1 is a bad version then set end = mid - 1
  if mid is not a bad version then set start = mid + 1
* Runtime: 68 ms
* Memory Usage: 36.3 MB
*
*/

var solution = function (isBadVersion) {
  /**
   * @param {integer} n Total versions
   * @return {integer} The first bad version
   */
  return function (n) {
    let start = 0,
      end = n;
    while (start <= end) {
      let mid = Math.floor((end + start) / 2);
      if (isBadVersion(mid)) {
        if (!isBadVersion(mid - 1)) {
          return mid;
        } else {
          end = mid - 1;
        }
      } else {
        start = mid + 1;
      }
    }
    return -1;
  };
};
