#include<bits/stdc++.h>
using namespace std;
int bsearch(int arr[], int low, int high, int key){
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]<key){
			low=mid+1;
		}
		else if(arr[mid]>key){
			high=mid-1;
		}
		else return mid+1;
		//cout<<mid<<endl;
	}
	return -1;
}
int main(){
	int size,e,n,rank_case;
	cin>>size; 
	int a[size]; 
	for(int i=0;i<size;i++){
		cin>>e;
		a[i]=e;
	}
	sort(a,a+size);

	cin>>n;
	while(n--){
		cin>>rank_case;
		cout<<bsearch(a,0,size-1,rank_case);
	}
}
