#include <stdio.h>
int main() {

  int i, n;

  // initialize starting two terms
  int f1 = 0, f2 = 1;

  // initialize the next term
  int nextTerm = f1 + f2;

  // get no. of terms from user
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  // print the first two terms f1 and f2
  printf("Fibonacci Series: %d, %d, ", f1, f2);

  // print 3rd to nth terms
  for (i = 3; i <= n; ++i) {
    printf("%d, ", nextTerm);
    f1 = f2;
    f2 = nextTerm;
    nextTerm = f1 + f2;
  }

  return 0;
}

