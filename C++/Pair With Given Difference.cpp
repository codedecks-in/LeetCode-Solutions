#include<bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<int,int>m;
	int a[]={5, 10, 3, 2, 50, 80};
	int diff=78;
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++){
		m[a[i]+diff]=1;
	}
	for(int i=0;i<n;i++){
		if(m.find(a[i])!=m.end()){
			cout<<1;
			return 0;
		}
	}
	cout<<0;
}
