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



int main(){
 ll T;
 cin>>T;
 tc(t,T){
 	ll n;
 	cin>>n;
 	char grid[n][n];
 	char grid2[n][n];
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			cin>>grid[i][j];
 			grid2[i][j]=grid[i][j];
 		}
 	}
 	for(int i=1;i<n-1;i++){
 		if(grid2[0][i]=='X'){
 			if(grid2[0][i-1]=='X' && grid2[0][i+1]=='X')grid2[0][i]='O';
 		}
 	}
 	for(int i=1;i<n-1;i++){
 		if(grid2[n-1][i]=='X'){
 			if(grid2[n-1][i-1]=='X' && grid2[n-1][i+1]=='X')grid2[n-1][i]='O';
 		}
 	}
 	for(int i=1;i<n-1;i++){
 		if(grid2[i][0]=='X'){
 			if(grid2[i-1][0]=='X' && grid2[i+1][0]=='X')grid2[i][0]='O';
 		}
 	}
 	for(int i=1;i<n-1;i++){
 		if(grid2[i][n-1]=='X'){
 			if(grid2[i-1][n-1]=='X' && grid2[i+1][n-1]=='X')grid2[i][n-1]='O';
 		}
 	}
 	for(int i=1;i<n-1;i++){
 		for(int j=1;j<n-1;j++){
 			if(grid2[i][j]=='X'){
 			if(grid2[i-1][j]=='X' && grid2[i+1][j]=='X')grid2[i][j]='O';
 			
 		}
 			if(grid2[i][j]=='X'){
 			
 			if(grid2[i][j-1]=='X' && grid2[i][j+1]=='X')grid2[i][j]='O';
 		}
 		}
 	}
 	
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			cout<<grid2[i][j]<<" ";
 		}
 		nl;
 	
 	}
 	nl;
 }
 
}




























