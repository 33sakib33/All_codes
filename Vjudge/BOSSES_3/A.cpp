#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define cin1(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define ll long long
#define ull unsigned ll
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
#define vull vector<unsigned ll>
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


ull binaryexp(ll n,ll p){

    if(p==0) return 1;
    if(p%2==0) return binaryexp((n)*(n),p/2);
    else return ((n)*binaryexp(((n)*(n)),(p-1)/2));

}





int main(){
 vull a(19);
 vull b(20);
 for(int i=0;i<19;i++){
 	a[i]=i;
 }
 for(int i=0;i<20;i++){
 	b[i]=i+19;
 	
 }
 
 vull ss1;
 vull ss2;
 
 for (ull i = 0; i < binaryexp(2, 19); i++) {
		ull t = i;
		ull res=0;
		
		for (int j = 0; j < 19; j++) {
			if (t & 1)
				res+=binaryexp(3,a[j]);
			t >>= 1;
		}
		ss1.pb(res);
	}
	 for (ull i = 0; i < binaryexp(2, 20); i++) {
		ull t = i;
		ull res=0;
		for (int j = 0; j < 20; j++) {
			if (t & 1)
				res+=binaryexp(3,b[j]);
			t >>= 1;
		}
		ss2.pb(res);
	}	
	sort(ss1.begin(),ss1.end());
	sort(ss2.begin(),ss2.end());
/*	for(auto x:ss2){
		cout<<x<<endl;
	}*/
	ull wall=binaryexp(3,19);
	ull T;
	cin>>T;
	tc(t,T){
		ull n;
		cin>>n;
		if(n<wall){
		  auto itr=lower_bound(ss1.begin(),ss1.end(),n);
		  cout<<*itr<<endl;
		}
		else{
		 auto itr=(lower_bound(ss2.begin(),ss2.end(),n));
		 ull ans=*itr;
		 
		 itr--;
		 ull test1=*itr;
		 for(auto x:ss1){
		 	if(x+test1>=n){
		 		ans=min(x+test1,ans);
		 		break;
		 	}
		 	
		 }
		 
		cout<<ans<<endl;
		}
		
	}
	
}




























