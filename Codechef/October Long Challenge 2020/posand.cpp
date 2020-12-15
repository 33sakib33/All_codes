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



int main(){
	//freopen("output.txt","w",stdout);
 	ll T;
 	cin>>T;
 	tc(t,T){
 		
 		int n;
 		cin>>n;
 		int p=log2(n);
 		if(n==1){
 		cout<<1<<endl;
 		}
 		else if((1<<p)==n){
 			cout<<"-1\n";
 		}

 		else{
 		  vi a(n+45,0);
 		  a[0]=2;
 		  a[1]=3;
 		  a[2]=1;
 		  for(int i=3;i<n;i++){
 		  	a[i]=i+1;
 		  }
 		  for(int i=3;i<n-1;i++){
 		  	p=log2(i+1);
 		  	if((1<<p)==i+1){
 		  	 a[i]^=a[i+1];
 		  	 a[i+1]^=a[i];
 		  	 a[i]^=a[i+1];
 		  	}
 		  }
 		  for(int i=0;i<n;i++){
 		  	cout<<a[i]<<" ";
 		  }	
 		  cout<<endl;
 		}
 		 }
 		 
 		
 	
}





















