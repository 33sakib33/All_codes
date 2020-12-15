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

vll gr[27];
int color[27];
int flag1=0;
int fl2[27][27];
stack<ll> st;
void dfs(ll s,ll p){
color[s]=1;

for(auto x:gr[s]){
 	if(color[x]==1 && p!=x){
 		flag1=1;
 	}
 	else if(color[x]==0){
 		
 		dfs(x,s);
 	}
 
}
color[s]=2;
st.push(s);
}


int main(){
	ll T;
	cin>>T;
	tc(t,T){
		int fl[26]={};
		for(int i=0;i<27;i++){
			gr[i].clear();
			color[i]=0;
			for(int j=0;j<27;j++){
			 fl2[i][j]=0;
			}
			
		}
		
		while(!st.empty())st.pop();
		flag1=0;
		string s;
		cin>>s;
		fl[s[0]-'a']=1;
		for(int i=1;i<s.size();i++){
		  ll nodeu=s[i-1]-'a';
		  ll nodev=s[i]-'a';
		  fl[nodeu]=1;
		  fl[nodev]=1;
		  if(fl2[nodeu][nodev]==0){
		   gr[nodeu].pb(nodev);
		  gr[nodev].pb(nodeu);
		 fl2[nodeu][nodev]=1;
		 fl2[nodev][nodeu]=1;
		 }
		
		}
		int src=s[0]-'a';
		for(int i=0;i<26;i++){
			if(fl[i]==1){
				if(gr[i].size()>2){
					flag1=1;
				}
				else if(gr[i].size()==1){
					src=i;
				}
				
			}
			
		}
		
		
		dfs(src,-1);
		
		if(flag1)cout<<"NO\n";
		else{
		cout<<"YES\n";
		while(!st.empty()){
			char sx='a'+st.top();
				cout<<sx;
			st.pop();
		}
		for(int i=0;i<26;i++){
			if(fl[i]!=1)cout<<(char)('a'+i);
			
		}
		nl;
		}
		
	}
 
}




























