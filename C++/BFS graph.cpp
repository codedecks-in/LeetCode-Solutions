#include<bits/stdc++.h>
using namespace std;
int a[20][20], q[20],v,n,visited[20],f=0,r=-1,level[20],x,y,z,e;
void bfs(int v){
	for(int i=1;i<=n;i++){
		if(a[v][i] && !visited[i]){
			q[++r]=i;
		}
		if(a[v][i] && !visited[i] && !level[i]){
			level[i]=level[v]+1;
		}
	}
	if(f<=r){
		visited[q[f]]=1;
		bfs(q[f++]);
		
	}
}
int main(){
	printf("enter no of vertices: ");
	scanf("%d",&n);
	printf("enter no of edges: ");
	scanf("%d",&e);
	printf("enter adjacency matrix: \n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[x][y]=0;
		}
		visited[i]=0;
		q[i]=0;
		level[i]=0;
	}
	for(int i=1;i<=e;i++){
		scanf("%d",&x);
		scanf("%d",&y);
		a[x][y]=1;
		//a[y][x]=1;
	}
	v=3;
	level[v]=1;
	visited[2]=1;
	bfs(v);
	level[v]=1;
	printf("\n");
	for(int i=1;i<=n;i++){
		if(visited[i]){
			printf("level of %d: %d",i,level[i]);
			printf("vertex: %d\n",i);
		}
	}
}
