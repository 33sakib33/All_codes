#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
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
ll binaryexp(ll n,ll p){

    if(p==0) return 1;
    if(p%2==0) return binaryexp((n%mod)*(n%mod),p/2);
    else return ((n%mod)*binaryexp(((n%mod)*(n%mod))%mod,(p-1)/2)%mod);

}

ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return ((a%mod * b%mod)%mod)* binaryexp(g,mod-2);
}
void printStack(stack<string> s){
    if(s.empty())return;

    string x=s.top();
    s.pop();
    printStack(s);
    cout<<x;
    s.push(x);

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
ll tree[3*200007];
ll arr[2*200007];
void buildtree(ll node,ll s,ll e){
 if(s==e){
 	tree[node]=arr[s];
 	return ;
 }
 ll mid1=(s+e)/2;
 buildtree(2*node,s,mid1);
 buildtree(2*node+1,mid1+1,e);
 tree[node]= lcm(tree[2*node],tree[2*node+1]);

}
ll query(ll node,ll s,ll e,ll le,ll ri){
if (le > ri) 
        return 0;
    if (s == le && e == ri) {
        return tree[node];
    }
     ll mid1=(s+e)/2;
    return lcm(query(node*2, s,mid1 , le, min(ri, mid1))
           ,(node*2+1, mid1+1, e, max(le, mid1+1), ri));
}




int main(){
 	ll n,q;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>arr[i];
 	}
 	cin>>q;
 	ll last=0;
 	buildtree(1,1,n);
 	for(int i=1;i<=3*n;i++)
	cout<<tree[i]<<" ";
 	for(int i=0;i<q;i++){
 		int x,y;
 		cin>>x>>y;
 		ll range1=(last+x)%n+1;
 		ll range2=(last+y)%n+1;
 		ll ans =query(1,1,n,range1,range2);
 		cout<<ans<<endl;
 		last=ans;
 	}
}


























