#include<bits/stdc++.h>
using namespace std;
int func(int x){
	return 2*x*x - 12*x + 7;
}
float findx(int l, int r){
	while(r-3>=l){
		int mid1=l+(r-l)/3;
		int mid2=r-(r-l)/3;
		if(func(mid1)>func(mid2)){
			l=mid1+1;
		}
		else{
			r=mid2-1;
		}
	}
	if(r==l) return func(r);
	if(r-l==1) return min(func(r), func(l));
	if(r-l==2) return min(func(l), min(func(l+1), func(l+2)));
}
int main(){
	int left,right;
	int interval;
	//cout<<func(5);
	cin>>interval;
	while(interval--){
		cin>>left>>right;
		cout<<findx(left, right);
	}
}
