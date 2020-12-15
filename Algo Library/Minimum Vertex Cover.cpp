#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[100005];
vector<ll> adj[100005];
ll dp[2][100005];
ll n;

void minimum_vertex_cover(ll child,ll parent){
	
	vis[child]=1;
	dp[0][child]=1; // state 0 is taking the vertex
	dp[1][child]=0; // state 1 is not taking the vertex
	
	for(auto itr1: adj[child]){
		if(vis[itr1]==0){
			minimum_vertex_cover(itr1,child);	
		}
	}
	for(auto itr1: adj[child]){
		if(parent!=itr1){
			dp[0][child]+=dp[1][itr1];
			dp[1][child]+=dp[0][itr1];
		}
	}
	dp[1][child]=min(dp[0][child],dp[1][child]); // As this is minimum vertex cover we try to take state 1.
	
	
}

void init(){
	cin>>n;
	memset(dp,0,sizeof(dp));
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n-1;i++){
		ll u;
		ll v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	minimum_vertex_cover(1,-1);
	ll ans=min(dp[0][1],dp[1][1]);
	cout<<ans<<endl;
	
	
}
int main(){
	init();
}
