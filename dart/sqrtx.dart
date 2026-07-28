/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.

The returned integer should be non-negative as well.
*/

class Solution {
  int mySqrt(int x) {
    if (x < 2) {
      return x;
    }

    int left = 1;
    int right = x ~/ 2;
    int ans = 1;

    while (left <= right) {
      final int mid = left + ((right - left) ~/ 2);
      final int square = mid * mid;

      if (square == x) {
        return mid;
      } else if (square < x) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return ans;
  }
}
