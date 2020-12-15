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
#define ul unsigned ll
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

 ul mx= 1000000000000000001;

int main(){
 	ul n,m;
 	cin>>n>>m;
 	ll flag=0;
 	vector<ul> a(m,0);
 	ll ans=0;
 	for(int i=0;i<m;i++){
 		cin>>a[i];
 		if(a[i]==1)flag=1;
 	}
 	if(flag==0){
 	vector<ul> lcm;
 
    ll count = pow(2, m);

    for (ll i = 0; i < count; i++) {
         ll xx=1;
           ll xx2=0;
           ll xx3=0;
        for (ll j = 0; j < n; j++) {
         
            if ((i & (1 << j)) != 0){
            	xx*=a[j];
            	if(xx2==0)xx2=a[j];
            	else xx2=gcd(xx2,a[j]);
            	xx3+=log10(a[j]);
            }
                
        }
        if(xx3>18)lcm.pb(0);
        else {
        	ll lx=xx/xx2;
        	lcm.pb(lx);
        }
    }


 	for(auto x:lcm){
 		if(x!=0){
 		 ans-=(ll)(n/x);
 		}
 	}
 	for(int i=0;i<m;i++){
 		ans+=(ll)(n/a[i]);
 	}
 	}
 	else{
 		ans=n;
 	}
 
 	cout<<ans<<endl;
 	
}




























