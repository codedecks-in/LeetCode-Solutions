#include<bits/stdc++.h>
using namespace std;
bool A[][];
void initialize(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			A[i][j]=false;
		}
	}
}
int main(){
	int nodes,edges,x,y,Q,a,b;
	initialize();
	cin>>nodes;
	cin>>edges;
	for(int i=0;i<edges;++i){
		cin>>x>>y;
		A[x][y]=true;
		A[y][x]=true;
	}
	cin>>Q;
	while(Q--){
		cin>>a>>b;
		if(A[a][b]) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}
