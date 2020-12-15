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
bool sortbysec(const pll &a,
              const pll &b)
{
    return (a.second < b.second);
}
/*bool cxp pair<ll, pll> &a,
              const pair<ll, pll> &b)
{
    return (a.ff < b.ff);
}*/



int main(){
	//freopen("output.txt","w",stdout);
 	ll T;
 	cin>>T;
 	tc(t,T){
 	 ll n,x,k,p;
 	 cin>>n>>x>>p>>k;
 	 vll a(n,0);
 	 rep(i,0,n,1){
 	 	cin>>a[i];
 	 }
 	  ll pos=-1;
 	  ll ans=-1;
 	 sort(a.begin(),a.end());
 	 if(n==1){
 	 if(a[0]!=x)
 	  ans=1;
 	  else ans=0;
 	 } 
 	 else if(p>k){
 		if(x>=a[p-1]){
 		pos=n;
 	 	for(ll i=p-1;i<n;i++){
 	 	  if(a[i]>=x){
 	 	   pos=i;
 	 	   break;
 	 	  }
 	 	}
 	 	ans=pos-(p-1);
 	 	}
 	 	
 	 }
 	 else if(p<k){
 	 	if(x<=a[p-1]){
 	 	pos=-1;
 	 	for(ll i=p-1;i>=0;i--){
 	 	  if(a[i]<=x){
 	 	   pos=i;
 	 	   break;
 	 	  }
 	 	}
 	 	ans=(p-1)-pos;
 	 	}
 	 	
 	 }
 	 else{
 	 	ll pos1=n;
 	 	ll pos2=-1;
 	 	
 	 	if(a[p-1]<x){
 	 	
 	 	for(ll i=p-1;i<n;i++){
 	 		if(a[i]>=x){
 	 			pos1=i;
 	 			break;
 	 		}
 	 	}
 	 	ans=pos1-p+1;
 	 	}
 	 	else{
 	 	for(ll i=p-1;i>=0;i--){
 	 		if(a[i]<=x){
 	 			pos2=i;
 	 			break;
 	 		}
 	 	}
 	 	ans=(p-1-pos2);
 	 	}
 	 	
 	 
 	 }
 	 cout<<ans<<endl;	
 	} 
 		
 
}





















