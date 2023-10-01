#include <bits/stdc++.h>
using namespace std;




int firstMissingPositive(vector<int> &A) {
// A[i] should be positioned at A[i]-1 if A[i]>0
// But in case of repeated characters, consider this case: 1 2 3 1 4 6 3
// Here 2 should be on the third position.
// But if we somehow could break this into : 1 2 3 4 missing 6 ...
// i.e have a sequence and separate the repeating characters.
// then we can get answer in just one iteration by checking if A[i]!=i+1 return i+1


// To "convert" our array, what we need to do is simple: Just swap the 
// elements with elements at their correct position. But why should it work for repeated
// elements? Simple, because it does.

// What it effectively does is that it would postion repeated elements to 
// the missing element position. 
int n=A.size();
for(int i=0;i<n;i++)
{
    // If A[i] is already at correct position or have no valid position
    if(A[i]==i+1||A[i]<=0||A[i]>n||A[i]==A[A[i]-1])continue;

    // else swap the element with its correct postion.
    swap(A[i],A[A[i]-1]);
    i--;

}

// First element which would not be at correct position would be our answer

for(int i=0;i<n;i++)
{
    if(A[i]!=i+1)
        return i+1;
}
return n+1;

}


int main() {
    vector<int> A={1,2,3,1,4,6,3};
    cout<<firstMissingPositive(A);
    return 0;
}