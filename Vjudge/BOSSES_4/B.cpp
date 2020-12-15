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

const int MAX =1007;

int dp[MAX];
vi a(2007,INT_MIN);
int b[1007];
int c[1007];
int d[1007];

int n,m,c0,d0;

int solve(int i,int dough,vi v){
	if(dough<=0){
		return 0;
	}
	
	if(dp[dough]!=-1){
		return dp[dough];
	}
	if(i==MAX+7)return 0;
	
	int ans=0;
	
		int p1=0;
		int p2=0;
		int p3=0;
		int p4=0;
		int p5=0;
		if(v[i]>=b[i] && dough>=c[i]){
			v[i]-=b[i];
			p1=d[i]+solve(i,dough-c[i],v);
			p3=solve(i+1,dough,v);
			if(dough>=c0)
			p4=d0+solve(i+1,dough-c0,v);
			
			
		}
		if(dough>=c0){
			p5=max(d0+solve(i+1,dough-c0,v),solve(i+1,dough,v));;
		}
		ans=max({p1,p2,p3,p4});
	
	dp[dough]=ans;
	return dp[dough];

}

int main(){
 cin>>n>>m>>c0>>d0;
 memset(dp,-1,sizeof(dp));
 memset(b,INT_MAX,sizeof(dp));
 memset(c,INT_MAX,sizeof(dp));
 memset(d,INT_MIN,sizeof(dp));
 for(int i=0;i<m;i++){
 	cin>>a[i]>>b[i]>>c[i]>>d[i];
 }
 int ans=solve(0,n,a);
 cout<<ans<<endl;
}




























