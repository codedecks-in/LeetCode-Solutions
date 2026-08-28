#include<bits/stdc++.h>
using namespace std;
void insertionsort(int a[],int n, int b[]){
	for(int i=0;i<n;i++){
		int j=i;
		int temp=a[i];
		while(j>=0 && temp<a[j-1]){
			a[j]=a[j-1];
			j--;
		}
		b[j]=i;
		a[j]=temp;;
	}
}
int main(){
	int n,e;
	cin>>n;
	int arr[n];
	int brr[n];
	for(int i=0;i<n;i++){
		cin>>e;
		arr[i]=e;
	}
	insertionsort(arr,n,brr);
	for(int i=0;i<n;i++){
		cout<<brr[i]<<" ";
	}
}
