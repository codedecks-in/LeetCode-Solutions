#include<bits/stdc++.h>
using namespace std;

int findCnt(int set[], int n, int sum)
{
	
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0)
		return false;

	// If last element is greater than sum,
	// then ignore it
	if (set[n - 1] > sum)
		return findCnt(set, n - 1, sum);

	/* else, check if sum can be obtained by any
of the following:
	(a) including the last element
	(b) excluding the last element */
	return findCnt(set, n - 1, sum) + findCnt(set, n - 1, sum - set[n - 1]);
}

// Driver code
int main()
{
	int n = 4;
    int a[] = {3,3,3,3};
    int sum = 6;
 
    cout << (findCnt(a, n, sum));
}

