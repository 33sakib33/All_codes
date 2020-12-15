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

ll dp[3007][3007];
pll pr[3007][3007];
ll n,m;
string s1,s2;
ll solve(ll i,ll j){
	if(i>=n || j>=m){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	ll p1=0;
	ll p2=0;
	ll ans=0;
	ll max1=0;
	pll td;
	if(s1[i]==s2[j]){
		ll x=solve(i+1,j+1);
		if(max1<x){
			max1=x;
			td={i+1,j+1};
			
		}
		ans=1+max1;
		
			
	}
	else{
		p1=solve(i+1,j);
		p2=solve(i,j+1);
		if(p1>=p2){
			td={i+1,j};
			max1=p1;
		}
		else{
			td={i,j+1};
			max1=p2;
		}
		ans=max1;
	}
	
	dp[i][j]=ans;
	pr[i][j]=td;
	return ans;
}


int main(){
 	memset(dp,-1,sizeof(dp));
 	cin>>s1>>s2;
 	n=s1.size();
 	m=s2.size();
 	ll ans=solve(0,0);
 	cout<<ans<<endl;
 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			cout<<pr[i][j].ff <<" "<<pr[i][j].ss <<"         ";
		}
		nl;
 	}
}




























