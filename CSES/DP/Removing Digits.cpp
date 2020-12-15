#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define cin1(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define ll long long
#define mp make_pair
#define pb push_back
#define nl printf("\n")
#define ff first
#define ss second
#define set0(a) memset ((a), 0 , sizeof(a))
#define set1(a) memset((a),-1,sizeof (a))
#define pi pair<int, int>
#define ps pair<string, string>
#define pl pair<long, long>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vl vector<long>
#define vi vector<int>
#define vs vector<string>
#define vps vector< ps >
#define vpi vector< pi >
#define vpl vector< pl >
#define vpll vector< pll >
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc(t,T) for(long long t=0;t<T;t++)
#define rep(i,s,n,d) for(long long i=s;i<n;i=i+d)
const int todx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
const int tody[] = { -1,  1, -2,  2, -2,  2, -1,  1 };
ll dp[1000006];
ll minpath(ll n){
	
	if(n==0)return 0;
	if(dp[n]!=-1)return dp[n];
	
	ll p1=mod;
	ll n2=n;
	while(n2>0){
		ll dig=n2%10;
		n2/=10;
		if(dig==0)continue;
		p1=min(p1,1+minpath(n-dig));
	}
	dp[n]=p1;
	return p1;
}

int main(){
   ll n;
   cin>>n;
   memset(dp,-1,sizeof(dp));
   dp[0]=0;
   
   cout<<minpath(n)<<endl;
}




























