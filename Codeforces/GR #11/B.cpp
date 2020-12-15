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




int main(){
	 //freopen("input.txt","r",stdin);
 	ll T;
 	cin>>T;
 	tc(t,T){
		ll n;
		ll k;
		cin>>n>>k;
	
		string s;
		cin>>s;
		ll last1=0;
		
		vll zer(n,0);
		vll sg;
		ll cnt=0;
		if(s[0]=='W')cnt=1;
		for(int i=1;i<n;i++){
		  if(s[i]=='W'){
		  	if(s[i-1]=='W')cnt+=2;
		  	else cnt+=1;
		  }
		}
		
		if(s[0]=='L')zer[0]=1;
		if(n==1)sg.pb(zer[0]);
		for(int i=1;i<n;i++){
		 if(s[i]=='L'){
		 	zer[i]=1;
		 	zer[i]+=zer[i-1];
		 }
		 else{
		     if(s[i-1]=='L'){
		     	sg.pb(zer[i-1]);
		     }
		 }
		 if(i==n-1){
		 	if(s[i]=='L'){
		 	  sg.pb(zer[i]);
		 	  last1=zer[i];
		 	}
		 }
		}
		ll max1=0;
		for(int i=0;i<n;i++){
			if(zer[i]>=1){
				max1=max(max1,zer[i]);
			}
			else{
			  break;
			}
		}
		
		int flag1=0;
		int flag2=0;
		sort(sg.begin(),sg.end());
		if(cnt==0)cnt=-1;
		for(auto x:sg){
			if(x<=k){
				if(flag1==0 && x==max1){
					flag1=1;
					continue;
				}
				else if(flag2==0 && x==last1){
					flag2=1;
					continue;
				}
				else{
				cnt+=2*x+1;
				k-=x;
				}
			}	
			else{
			 	cnt+=2*min(x,k);
			 	k=0;
			 	break;
			}
		}
		if(flag1==1){
			if(n!=1){
			cnt+=2*min(k,max1);
			}
			else cnt=1;
			k=k-min(k,max1);
		}
		if(flag2==1){
			if(n!=1){
			cnt+=2*min(k,last1);
			}
			else cnt=1;
			k=k-min(k,last1);
			
		}
		
		if(cnt==-1)cnt=0;
		//cout<<s<<endl;
		cout<<cnt<<endl;
			
 	}
}




























