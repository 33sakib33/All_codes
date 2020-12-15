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


#define meax 1000007
vll spf(meax,0);
vll primes;
void siv(){
    spf[1]=-2131;
    spf[0]=-213;

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
    for(int i=2;i<meax;i++){
    	if(spf[i]==i){
    	 primes.pb(i);
    	}
    }
}



int main(){
 siv();
 int T;
 scanf("%d",&T);
 tc(t,T){
 	int n;
 	scanf("%d",&n);
 	int up=0;
 	int down=0;
 	for(int i=n;i<meax;i++){
 		if(spf[i]==i){
 			up=i;
 			break;
 		}
 	}
 	for(int i=n;i>=0;i--){
 		if(spf[i]==i){
 			down=i;
 			break;
 		}
 	}
 	int ans=0;
 	if(down==0){
 		ans=up;
 	}
 	else if(up==0){
 		ans=down;
 	}
 	else if((n-down)<(up-n)){
 		ans=down;
 	}
 	else if(n-down==up-n){
 		ans=down;
 	}
 	else{
 		ans=up;
 	}
 	printf("%d\n",ans);
 }
}




























