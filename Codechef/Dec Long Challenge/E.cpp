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
int msbDeBruijn32( int v )
{
    static const int MultiplyDeBruijnBitPosition[32] =
    {
        0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
        8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31
    };

    v |= v >> 1; // first round down to one less than a power of 2
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;

    return MultiplyDeBruijnBitPosition[( int )( v * 0x07C4ACDDU ) >> 27];
}
int main(){
	flash;
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
		
		vector<priority_queue<int,vector<int>,greater<int> >> vpq(33);
		for(int i=1;i<n;i++){
			int cnt=30;	
			int x=1<<cnt;
			while(x>0){
			
				if(x&a[i]){
					vpq[cnt].push(i);
				}
				x=x>>1;
				cnt--;
			}
			
			
		}
		
		for(int i=0;i<n-1;i++){
			//double cnt1=ceil(log2(b[i]));
			int cnt=30;	
			int x=1<<cnt;
			//cout<<x<<endl;
			while(x>0 && cnt>=0){
				if(x&b[i]){
					if(vpq[cnt].top()==i){
						vpq[cnt].pop();
					}
					if(vpq[cnt].empty()){
						int index=n-1;
						vpq[cnt].push(n-1);
						b[index]=(b[index]|(1<<cnt));
					}
					else{
						int index=vpq[cnt].top();
						vpq[cnt].pop();
						b[index]=(b[index]&~(1<<cnt));
						
					}
					b[i]=b[i]&~(1<<cnt);
					k--;
				}
				x=x>>1;
				cnt--;
				if(k<=0)break;
			}
			if(k<=0)break;
			
	
		}
		if(k%2==1){
			b[n-2]=b[n-2]^(1<<0);
			b[n-1]=b[n-1]^(1<<0);
		}
		
		for(int i=0;i<n;i++){
			cout<<b[i]<<" ";
		}
		nl;
	}

}




























