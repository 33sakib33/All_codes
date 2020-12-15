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


ll fcarr[1000];
ll fact(ll n){
	if(fcarr[n]!=0){
		return fcarr[n];
	}
	fcarr[0]=1;
	fcarr[1]=1;
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans%mod)*(i%mod);
		ans%=mod;
		fcarr[i]=ans;
	}
	return fcarr[n];
}
ll npr(ll n,ll r){
	if(n<r)return 0;
	ll ans=1;
	for(int i=n;i>=n-r+1;i--){
		ans=((ans%mod)*(i%mod))%mod;
	}
	return ans;

}

int main(){
 	ll n,x,pos;
 	cin>>n>>x>>pos;
 	ll left=0;
 	ll right=n;
 	ll count1=0;
 	ll count2=0;
 	ll mid=0;
 	
 	while(left<right){
 		mid=(left+right)/2;
 		if(mid<=pos){
 			left=mid+1;
 			if(mid!=pos)
 			count1++;
 			
		}
		else{
			right=mid;
			if(mid!=pos)
			count2++;
			
		}
 		
 	}
 	ll ans= npr(x-1,count1);
 	ans=((ans%mod)* npr(n-x,count2)%mod)%mod;
	ans=(ans* fact(n-(count1+count2+1))%mod)%mod;
	/*cout<<count1<<endl;
	cout<<count2<<endl;*/
 	cout<<ans<<endl;
 	
}




























