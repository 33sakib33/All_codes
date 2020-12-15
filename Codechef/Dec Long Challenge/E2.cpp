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
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc(t,T) for(long long t=0;t<T;t++)
#define rep(i,s,n,d) for(long long i=s;i<n;i=i+d)

int main(){
	//flash;
	ll T;
	cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		vll a(n);
		vll b(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		
		vll arr(60,0);
		ll loan=0;
		for(int i=0;i<n-1;i++){
			ll cnt=40;
			ll x=1LL<<cnt;
			while(x>0){
				if(x&b[i]){
				  //cout<<b[i]<<" "<<i<<endl;
				  if(arr[cnt]==1){
				  b[i]=b[i]^(1<<cnt);
				  arr[cnt]=0;
				  } 
				  else if(k>0){
				  b[i]=b[i]^(1<<cnt);
				  arr[cnt]=1;
				  k--;
				  } 
				} 
				x=x/2;
				cnt--;
				//if(k<=0)break;
			}
			//if(k<=0)break;
		}
		for(int i=0;i<40;i++){
			if(arr[i]==1){
				b[n-1]=b[n-1]^(1<<i);
			}
		}
		ll zc=0;
		for(int i=0;i<n;i++){
			if(b[i]==0)zc++;
		}
		cout<<zc<<endl;
		if(k%2==0 && zc==n){
			
			ll x=b[n-2]^(1<<0);
			ll y=b[n-1]^(1<<0);
		}
		
		for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
		}
		nl;
	}

}




























