#include<iostream>
using namespace std;
int n=10;
int INF=1000;
int G[10][10], C[10][10], visited[10], dist[10], pred[10], start,v,nextnode,e;
void dijk(int start){
	int count, mindist, node;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			if(G[i][j]==0){
				C[i][j]=INF;
			}
			else{
				C[i][j]=G[i][j];
			}
		}
	}
	for(int i=1;i<=v;i++){
		dist[i]=C[start][i];
		visited[i]=0;
		pred[i]=start;
	}
	dist[start]=0;
	visited[start]=1;
	count=1;
	while(count<v){
		mindist=INF;
		for(int i=1;i<=v;i++){
			if(dist[i]<mindist && !visited[i]){
				mindist=dist[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;
		for(int i=1;i<=v;i++){
			if(!visited[i]){
				if(mindist+C[nextnode][i]<dist[i]){
					dist[i]=mindist+C[nextnode][i];
					pred[i]=nextnode;
				}
			}
		}
		count++;
	}
	for(int i=1;i<=v;i++){
		if(i!=start){
			cout<<"The distance of node "<<i<<" is "<<dist[i];
			int j=1;
			do{ j=pred[j];
				cout<<"<-"<<j;
			}while(j!=start);
		}
	}
}
int main(){
	cout<<"Enter v: ";
	cin>>v;
	cout<<"\nEnter e:";
	cin>>e;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			G[i][j]=0;
		}
	}
	cout<<"Enter matrix: \n";
	for(int i=1;i<=e;i++){
		for(int j=1;j<=e;j++){
			cin>>G[i][j];
		}
	}
	cout<<"Enter starting node: ";
	cin>>start;
	dijk(start);
}
