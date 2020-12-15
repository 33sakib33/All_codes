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


vll tp;
vll tp2;
const ll mx=10e5+7;
ll vis[mx];
ll ind[mx];
ll out[mx];
set<pll> st;
ll n;
void topo(ll u,ll v){
	vis[u]=1;
	for(int i=u+1;i<=n;i++){
		if(st.find({u,i})!=st.end()){
			continue;
		}
		if(vis[u]==0){
			vis[i]=1;
			topo(i,u);
		}
	}
	tp2.pb(u);
	cout<<u<<endl;
}


int main(){
 	ll T;
 	cin>>T;
 	tc(t,T){
 		ll m;
 		cin>>n>>m;
 		for(int i=0;i<=n;i++){
 		vis[i]=0;
 		ind[i]=i-1;
 		out[i]=n-i;
 		}
 		tp.clear();
 		st.clear();
 		
 		tp2.clear();
 		for(int i=0;i<m;i++){
 			ll a,b;
 			cin>>a>>b;
 			st.insert({a,b});
 			ind[b]--;
 			
 			out[a]--;
 		}
 		int kx=0;
 		for(int i=n;i>1;i--){
 			if(ind[i]<=0 && out[i]==0){
 			tp.pb(i);
 			vis[i]=1;
 			kx++;
 			}
 		}
 		for(int i=n;i>=1;i--){
 			if(vis[i]==0 && ind[i]==0){
 				topo(i,-1);
 			}
 		}
 		//reverse(tp2.begin(),tp2.end());
 		vll ans(n+7,0);
 		int fi=0;
 		int fj=0;
 		for(int i=0;i<kx;i++){
 			cout<<tp[i]<<" ";
 			cout<<"baal1"<<endl;
 			
 		}
 		nl;
 		for(int j=0;j<n-kx;j++){
 			cout<<tp2[j]<<" ";
 			cout<<"baal"<<endl;
 		}
 		nl;
 		for(int i=1;i<=n;i++){
 			if(fi<kx && fj<n-kx){
 			if(tp[fi]>tp2[fj]){
 				ans[i]=tp[fi++];
 				
 			}
 			else ans[i]=tp2[fj++];
 			}
 			else{
 			if(fi<kx)ans[i]=tp[fi++];
 			if(fj<n-kx)ans[i]=tp2[fj++];
 			}
 		}
 		for(int i=1;i<=n;i++){
 			cout<<ans[i]<<" ";
 		}
 		nl;
 		
 	}
}




























