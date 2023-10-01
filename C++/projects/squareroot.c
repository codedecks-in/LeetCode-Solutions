#include <stdio.h>
#include <math.h> // for 'fabs' - returns unsigned absolute value

const double MAX_ERROR = 1e-7; // equivalent to 10^-7 -> accurate upto 7 decimal places
							   // can be set according to need or even taken in as input 

double squareRoot(int x)
{
	double r = 1; // initial guess for the root
	while (fabs(r*r - x) > MAX_ERROR)
	{
		r = (r + x/r) / 2; 
		// value of 'r' moves closer and closer to the actual root value
	}

	return r;
}

int main()
{
	// the number for which we expect to compute the root
	int num;
	scanf("%d", &num);

	printf("%lf \n", squareRoot(num));

	return 0;
}
