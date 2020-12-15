#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll knapsack(vector<pair<ll,ll>> &a,ll n, ll w){
	ll dp[w+2];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	//sort(a.rbegin(),a.rend());
	for(int i=0;i<n;i++){
		
		for(int j=w;j>=0;j--){
			if(j>=a[i].first){
			dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
			}
		}
		
	}
	return dp[w];
}
void init(){
	ll n,w;
	cin>>n>>w;
	vector<pair<ll,ll>> a(100005);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	ll ans=knapsack(a,n,w);
	cout<<ans<<endl;
}
int main(){
	init();
}
