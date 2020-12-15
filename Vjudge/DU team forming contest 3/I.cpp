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
void printStack(stack<string> s){
    if(s.empty())return;

    string x=s.top();
    s.pop();
    printStack(s);
    cout<<x;
    s.push(x);

}





int main(){
 	stack<pll> st;
 	ll n;
 	cin>>n;
 	
 	vll a(n+1,0);
 	vll a1(n+1,0),a2(n+1,0);
 	st.push({-1,-1});
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 	}
 	
 	for(int i=1;i<=n;i++){
 		if(st.empty()){
 			a1[i]=-1;
 			st.push({a[i],i});
 		}
 		while(st.top().ff>=a[i]){
 			st.pop();
 		}
 		if(st.empty()){
 			a1[i]=-1;
 			st.push({a[i],i});
 		}
 		else{
 			a1[i]=st.top().ss;
 			st.push({a[i],i});
 		}
 	}
 	
 	while(!st.empty())st.pop();
 	st.push({-1,n+1});
 	for(int i=n;i>=1;i--){
 		if(st.empty()){
 			a2[i]=n;
 			st.push({a[i],i});
 		}
 		while(st.top().ff>=a[i]){
 			st.pop();
 		}
 		if(st.empty()){
 			a2[i]=n;
 			st.push({a[i],i});
 		}
 		else{
 			a2[i]=st.top().ss;
 			st.push({a[i],i});
 		}
 	}
 	ll s1=0;
 	for(int i=1;i<=n;i++){
 		ll size1= (a2[i]-a1[i]);
 		cout<<a2[i]<<" "<<a1[i]<<endl;
 		cout<<size1<<endl;
 		if(size1>n){
 			size1=n;
 		}
 		else if(size1==2){
 			size1=1;
 		}
 		s1+=(a[i]*size1);
 	}
 	cout<<s1<<endl;
}



























 	
