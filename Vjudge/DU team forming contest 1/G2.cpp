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
map<pi,ll> ans;
int s1[mx];
vector<vector<ll>> a;
ll self(int i,int j){
 	int i1=min(i,j);
	int i2=max(i,j);
	if(ans.find({i1,i2}) !=ans.end()){
		return ans[{i1,i2}];
	}
	ll ans1=0;
	for(int k=0;k<s1[i];k++){
		for(int k2=k+1;k2<s1[i];k2++){
		  ans1=ans1+ 2*abs(a[i][k]-a[i][k2]);
		}
	}
	ans[{i1,i2}]=ans1;
	return ans1;
	
}
ll os(int i, int j){
       int i1=min(i,j);
	int i2=max(i,j);
	if(ans.find({i1,i2}) !=ans.end()){
		return ans[{i,j}];
	}
	ll ans1=0;
	for(int k=0;k<s1[i];k++){
		for(int k2=0;k2<s1[j];k2++){
		  ans1=ans1+abs(a[i][k]-a[j][k2]);
		}
	}
	
	ans[{i1,i2}]=ans1;
	return ans1;
}
int main(){
	flash;
 	ll k,m;
 	cin>>k;
 	a.resize(k);
 	for(int i=0;i<k;i++){
 	cin>>s1[i];
 	//a[i].resize(s1[i]);
 	for(int j=0;j<s1[i];j++){
		ll inp;
		cin>>inp;
		a[i].pb(inp);
 	}
 	}
 	cin>>m;
 	for(int i=0;i<m;i++){
 	int a,b;
 	cin>>a>>b;
 	ll res=0;
 	if(a==b){
 	res=self(a-1,b-1);
	}
	else{
	res=os(a-1,b-1);
	}
	cout<<res<<endl;
	
 	}
 	
 	
}




























