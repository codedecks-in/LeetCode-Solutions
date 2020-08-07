/*
*
*
* Runtime : 4 ms
* Memory  : 6 MB
* 
*
*/
class Solution {
  public:

    int integerBreak(int n) {

	// when n = 0,1 no possible cuts hence store 0
      int val[n + 1];
      val[0] = val[1] = 0;

	// calculate for all possible cuts possible from 1 to n
      for (int i = 1; i <= n; i++) {
        int max_value = INT_MIN;
	
	/*for n = 6 calculate for all possible cuts like maximum of
	 {(1,5),(5,1)}, {(4,2),(2,4)},{ (3,3) }
	*/	
        for (int j = 1; j <= i / 2; j++) {
          max_value = max(max_value, max((i - j) * j, j * val[i - j]));
        }

        val[i] = max_value;
      }

      return val[n];

    }
};
