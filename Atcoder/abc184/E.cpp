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
const int todx[] = { 1,  0,  0,  -1};
const int tody[] = { 0,  1, -1,  0};
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
void printStack(stack<string> s){
    if(s.empty())return;

    string x=s.top();
    s.pop();
    printStack(s);
    cout<<x;
    s.push(x);

}


ll binaryexp(ll n,ll p){

    if(p==0) return 1;
    if(p%2==0) return binaryexp((n%mod)*(n%mod),p/2);
    else return ((n%mod)*binaryexp(((n%mod)*(n%mod))%mod,(p-1)/2)%mod);

}

#define meax 10000001
vll spf(meax,0);
void siv(){
    spf[1]=1;

   for(ll i=2;i<meax;i++)spf[i]=i;

   for(ll i=4;i<meax;i+=2){
        spf[i]=2;
    }
    for(ll i=3;i*i<meax;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<meax;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}
char grid[2006][2006];
ll dis[2006][2006];
bool vis[2006][2006];
ll sr,sc;
ll er,ec;
ll r,c;
ll flag[26];
vpll a[26];
void bfs(){
	queue<pair<ll,ll>>q;
	q.push({sr,sc});
	vis[sr][sc]=true;
	while(!q.empty()){
		pll tmp=q.front();
		ll x=tmp.ff;
		ll y=tmp.ss;
		q.pop();
		if(grid[x][y]>='a' && grid[x][y]<='z'){
			if(flag[grid[x][y]-'a']==0){
				for(auto itr:a[grid[x][y]-'a']){
					ll x1=itr.ff;
					ll y1=itr.ss;
					if(vis[x1][y1]==false){
						dis[x1][y1]=dis[x][y]+1;
						vis[x1][y1]=true;
						q.push({x1,y1});
					}
				}
				flag[grid[x][y]-'a']=1;
			}
		}
		for(int i=0;i<4;i++){
			ll x1=x+todx[i];
			ll y1=y+tody[i];
			
			if(min(x1,y1)<0 || x1>=r || y1>=c)continue;
			if(vis[x1][y1]==false && grid[x1][y1]!='#'){
			dis[x1][y1]=dis[x][y]+1;
			vis[x1][y1]=true;
			q.push({x1,y1});
			
			}
		}
	
	}
}

int main(){
 memset(vis,false,sizeof(vis));

 cin>>r>>c;
 for(int i=0;i<r;i++){
 	for(int j=0;j<c;j++){
 		cin>>grid[i][j];
 		if(grid[i][j]=='S'){
 			sr=i;
 			sc=j;
 		}
 		else if(grid[i][j]=='G'){
 			er=i;
 			ec=j;
 		}
 		else if(grid[i][j]!='.' && grid[i][j]!='#'){
 			a[grid[i][j]-'a'].pb({i,j});
 		}
 	}
 }
 bfs();
 ll ans=0;
 if(vis[er][ec]==false)ans=-1;
 else ans=dis[er][ec];
 cout<<ans<<endl;
 /*for(int i=0;i<r;i++){
 	for(int j=0;j<c;j++){
 		cout<<dis[i][j]<<" ";
 	}
 	nl;
 }*/
}




























