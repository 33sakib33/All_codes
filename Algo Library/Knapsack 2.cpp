#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll knapsack(vector<pair<ll,ll>> &a,ll n, ll w,ll sum){
	vector<ll> dp(sum+1,10e10);
	//memset(dp,LONG_MAX,sizeof(dp));
	dp[0]=0;
	//sort(a.rbegin(),a.rend());
	for(int i=0;i<n;i++){
		
		for(int j=sum;j>=0;j--){
			if(j>=a[i].second){
			dp[j]=min(dp[j],dp[j-a[i].second]+a[i].first);
			}
		}
		
	}
	ll ans=0;
	for(int i=sum;i>=0;i--){
		if(dp[i]<=w){
			ans=i;
			break;
		}
	}
	return ans;
}
void init(){
	ll n,w;
	cin>>n>>w;
	ll sum1=0;
	vector<pair<ll,ll>> a(100005);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		sum1+=a[i].second;
	}
	ll ans=knapsack(a,n,w,sum1);
	cout<<ans<<endl;
}
int main(){
	init();
}
