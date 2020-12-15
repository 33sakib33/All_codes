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
const int todx[] = { 0, 0, 1, -1};
const int tody[] = { -1, 1, 0, 0};
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

ll n,m;
ll r,c;
ll x,y;
pair<ll,ll> cnt[2007][2007];
int vis[2007][2007];
char s[2007][2007];
void bfs(pll s1){
	queue<pll> q;
	q.push(s1);
	cnt[s1.ff][s1.ss].ff=0;
	cnt[s1.ff][s1.ss].ss=0;
	vis[s1.ff][s1.ss]=1;
	while(!q.empty()){
		pll cor=q.front();
		q.pop();
		ll x1=cor.ff;
		ll y1=cor.ss;
		//vis[x1][y1]=1;
		for(int i=0;i<4;i++){
			ll x2=x1+todx[i];
			ll y2=y1+tody[i];
			if(min(x2,y2)<0 || x2>n || y2>m)continue;
			if(s[x2][y2]=='*'){
				continue;
			}
			if(vis[x2][y2]==0){
			  if(tody[i]==-1){
			   	if(cnt[x1][y1].ff+1>x)continue;
			   }
			   else if(tody[i]==1){
			   	if(cnt[x1][y1].ss+1>y)continue;
			   }
			   vis[x2][y2]=1;
			   cnt[x2][y2]=cnt[x1][y1];
			   if(tody[i]==-1){
			   	cnt[x2][y2].ff=cnt[x1][y1].ff+1;
			   }
			   else if(tody[i]==1){
			   	cnt[x2][y2].ss=cnt[x1][y1].ss+1;
			   }
			   q.push({x2,y2});
			   
			}
			
		}
	}
}



int main(){
 	cin>>n>>m;
 	cin>>r>>c;
 	cin>>x>>y;
 	
 	getchar();
 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			cin>>s[i][j];
 			cnt[i][j]={LONG_MAX,LONG_MAX};
 		}
 	}
 	bfs({r-1,c-1});
 	ll cnt1=0;
 	for(int i=0;i<n;i++){
 	for(int j=0;j<m;j++){
 		if(s[i][j]!='*'){
 			if(cnt[i][j].ff<=x && cnt[i][j].ss<=y){
 				cnt1++;
 			}
 		}
 		//cout<<cnt[i][j].ff<<" "<<cnt[i][j].ss<<"|  ";
 		
 	}
 
	}
	cout<<cnt1<<endl;
}




























