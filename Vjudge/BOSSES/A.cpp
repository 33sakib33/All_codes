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
ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

ll n;
ll m;
vll gr[207];
vll e(207,0);
int color[207];
int flag=0;
int mat[207][207];
int vis[207];
int cnt=0;
void dfs(ll s , ll p){
	vis[s]=1;
	color[s]=1;
	for(auto x:gr[s]){
		if(color[x]==1 && x!=p){
			cnt++;
			
		}
		else if(vis[x]==0){
			dfs(x,s);
		}
	}
	color[s]=2;

}

int main(){
	 cin>>n;
	 cin>>m;
	 for(int i=0;i<m;i++){
	 	ll a,b;
	 	cin>>a>>b;
	 	gr[a].pb(b);
	 	gr[b].pb(a);
	 	e[a]++;
	 	e[b]++;
	 }
	 dfs(1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
		  cnt=-1;
		}
	}
	 if(cnt==1){
	 	cout<<"FHTAGN!\n";
	 }
	 else cout<<"NO\n";
	 
	
	
	 
	 
}




























