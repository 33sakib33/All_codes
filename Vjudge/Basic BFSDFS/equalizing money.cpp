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

vi gr[1006];
int vis[1006];
int cost[1006];
int cp[1006];
int n,m;
int carry;
int average;

void dfs(int s,int c){
 	
 	vis[s]=1;
 	cp[s]=c;
 	if(cost[s]>average){
 		carry=carry+cost[s]-average;
 		cost[s]=average;
 	}
 	if(cost[s]<average){
 		carry=carry-(average-cost[s]);
 		cost[s]=average;
 	}
 	for(auto x:gr[s]){
 		if(vis[x]==0){
 			vis[x]=1;
 		 	dfs(x,c);
 		}
 	}
 	if(cost[s]>average){
 		carry=carry+cost[s]-average;
 		cost[s]=average;
 	}
 	if(cost[s]<average){
 		carry=carry-average;
 		cost[s]=average;
 	}
 	
}
void dfsrec(int s,int c){
   carry=0;
   dfs(s,c);

}

int main(){
    //freopen("output.txt","w",stdout);
    ll T;
    cin>>T;
    tc(t,T){
   	
   	int flag=0;
   	cin>>n;
   	cin>>m;
   	int sum1=0;
   	carry=0;
   	for(int i=1;i<=n;i++){
   	    cin>>cost[i];
   	    sum1+=cost[i];
   	}
   	for(int i=0;i<m;i++){
   		int u,v;
   		cin>>u>>v;
   		gr[u].pb(v);
   		gr[v].pb(u);
   	}
   	average=sum1/n;
   	if(sum1%n!=0){
   		flag=1;
   	}
   	else{
   		int cx=1;
   	   for(int i=1;i<=n;i++){
   	   	if(vis[i]==0){
   	   		dfsrec(i,cx);
   	   		if(carry!=0)flag=1;
   	   		
   	   	}
   	   }
   	   
   	}
   	
 	
   	   cout<<"Case "<<t+1<<": ";
   	   if(flag)cout<<"No"; 
   	   else cout<<"Yes";
   	   nl;
	memset(cost,0,sizeof(cost));
	memset(vis,0,sizeof(vis));
	memset(cp,0,sizeof(cp));
	for(int i=0;i<=n;i++)gr[i].clear();
}
}


















