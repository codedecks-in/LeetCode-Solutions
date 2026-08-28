#include<bits/stdc++.h>
using namespace std;
int bubblesort(int a[],int n){
	int count=0;
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n-1-k;i++){
			if(a[i+1]<a[i]){
				swap(a[i],a[i+1]);
				count++;	
			}
		}
	}
	return count;
}
int main(){
	int n,e;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>e;
		arr[i]=e;
	}
	cout<<bubblesort(arr,n);
}
