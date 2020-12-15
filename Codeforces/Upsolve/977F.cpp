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

void func(void)
{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
}
const int mx=200005;
const ll inf=2e9;

vll d(mx+1,inf);
ll n;

void solve(){
cin>>n;
vpll a(n,{0,0});
rep(i,0,n,1){
 	cin>>a[i].ff;
 	a[i].ss=i;
 }
 map<ll,pll> mp;
 ll ans=0;
 ll max1=0;
 ll key=0;
 
 for(int i=0;i<n;i++){
 	if(mp.find(a[i].ff)!=mp.end()){
 		continue;
 		
 	}
 	else if(mp.find(a[i].ff-1)==mp.end()){
 	mp[a[i].ff]={1,i};
 	}
 	else{
 	  mp[a[i].ff]={mp[a[i].ff-1].ff+1,i};
 	}
 	if(max1<mp[a[i].ff].ff){
 		max1=mp[a[i].ff].ff;
 		key=a[i].ff;
 		ans=i;
 		
 	}
 }
 cout<<max1<<endl;
vll ansv(n+1,0);
ll xz=0;

while(mp[key].ff!=1){
	ansv[xz++]=mp[key].ss;
	key=key-1;
}
ansv[xz++]=mp[key].ss;
for(ll j=xz-1;j>=0;j--){
	cout<<ansv[j]+1<<" ";	
}
nl;
}
int main(){
 	
 	solve();
}




























