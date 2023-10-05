#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[]={ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	int count=0;
	int n=sizeof(a)/sizeof(a[0]);
	int j=1;
	for(int i=0;j<n;i++){
		while(a[i]==a[j]){
			j++;
			count++;
		}
		a[i+1]=a[j];
		j++;
	}
	cout<<n-count<<endl;
	for(int i=0;i<n-count;i++){
		cout<<a[i]<<"\t";
	}
	return 0;
}
