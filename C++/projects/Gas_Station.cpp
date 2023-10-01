#include <bits/stdc++.h>
using namespace std;
// Given two integer arrays A and B of size N. There are N gas stations along a circular route, where the amount of gas at station i is A[i].

// You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

// You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.


int Solution(const vector<int> &A, const vector<int> &B) {
  
    int startIndex;
    int n = A.size(); //size of the vectors given
    for(int i = 0; i<n; i++) {
    startIndex = i;
    int gasleft = A[i] -B[i];
    while(gasleft >= 0 && (i - startIndex) < n) {
    gasleft += A[++i%n]-B[i%n];
    }
    if(gasleft >= 0 )
    return startIndex;
    }// end for
    return -1;
    
}




int main() {
    vector<int> A={1,2,3,1,4,6,3},B={3,6,4,1,3,2,1};
    cout<<Solution(A,B);
    return 0;
}
