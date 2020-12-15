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
bool custom(const pair<ll,pll> &a,const pair<ll,pll> &b){
     if(a.ss.ff*b.ss.ss== b.ss.ff*a.ss.ss){
     	return  (a.ff<b.ff);
     }
     
     return ( a.ss.ff*b.ss.ss< b.ss.ff*a.ss.ss);
  
    }
int main(){	
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	while(T--){
	int n;
	cin>>n;
	vector<pair<ll,pll>> a(n);
	for(int i=0;i<n;i++){
	ll x,y;
	cin>>x>>y;
	a[i].ff=i;
	a[i].ss.ff=x;
	a[i].ss.ss=y;
	}
	
	sort(a.begin(),a.end(),custom);
	cout<<a[0].ff+1;
	for(int i=1;i<n;i++){
		cout<<" "<<a[i].ff+1;
	}
	if(T!=0){
	nl;
	}
	}

}
