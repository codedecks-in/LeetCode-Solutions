//Shortest path in undirected graph using BFS.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> adj[10005];
ll dis[10005],vis[10005];

void bfs(ll src){
    
    queue<ll> q;
    vis[src]=1;
    dis[src]=0;
    q.push(src);
    
    while(!q.empty()){

        int node = q.front();
        q.pop();
        
        for(auto it : adj[node]){       //traversing in the adjacency list.
            if(vis[it]==0){
                dis[it]=dis[node]+1;
                q.push(it);
                vis[it]=1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    
    while(t--){

    ll n,m;   //no. of nodes & vertices.
    cin>>n>>m;
    
    for(ll i=0;i<=n;i++) adj[i].clear() , vis[i]=0;

    while(m--){
      ll a,b;
        cin>>a>>b;  adj[a].push_back(b);  adj[b].push_back(a);
    }
    
    bfs(1);       //calling the above BFS function.
  
    for(ll i = 1; i <= n; i++)    //printing path from source to ith node.
    cout<<dis[i]<<" ";
    
    cout<<endl;
    }
}