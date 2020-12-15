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
const int mx=10e5+7;
ll dp[3][mx];
ll a[3][mx];
ll n;
ll solve(ll i,ll k){
	if(i>=n){
		return 0;
	}
	if(i==n-1){
		dp[k][i]=a[k][i];
		return dp[k][i];
	}
	if(dp[k][i]!=-1)return dp[k][i];
	ll p1,p2;
	p1=p2=0;
	 p1=solve(i+1,(k+1)%3);
	 p2=solve(i+1,(k+2)%3);
	 ll ans=max(p1,p2);
	 dp[k][i]=ans+a[k][i];
	 return dp[k][i];

}


int main(){
 memset(dp,-1,sizeof(dp));
 cin>>n;
 rep(i,0,n,1){
 	cin>>a[0][i]>>a[1][i]>>a[2][i];
 }
 ll ans=0;
 for(int i=0;i<3;i++)
  ans=max(solve(0,i),ans);
  cout<<ans<<endl;
}




























