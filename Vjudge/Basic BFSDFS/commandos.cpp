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

int gr[101][101];

int vis[101];
int tx=1;
int n,m;
void bfs(int s, int *st){
 	queue<int> q;
 	q.push(s);
 	st[s]=0;
 	vis[s]=1;
 	while(!q.empty()){
 		int s1=q.front();
 		q.pop();
 		for(int i=0;i<n;i++){
 			if(gr[s1][i]==1){
 				if(vis[i]==0){
 					st[i]=st[s1]+1;
 					vis[i]=1;
 					q.push(i);
 				}
 			}
 		}
 	}
}

int main(){
    //freopen("output.txt","w",stdout);
    ll T;
    cin>>T;
    tc(t,T){
        int st[101];
        int st2[101];
      	 cin>>n>>m;
        memset(gr,0,sizeof(gr));
        memset(st,0,sizeof(st));
        memset(st2,0,sizeof(st2));
        memset(vis,0,sizeof(vis));
        tx=1;
        for(int i=0;i<m;i++){
           int u,v;
           cin>>u>>v;
          gr[u][v]=1;
          gr[v][u]=1;
        }
      int s,d;
      cin>>s>>d;
      bfs(s,st);
      memset(vis,0,sizeof(vis));
      bfs(d,st2);
      int ans=0;
      for(int i=0;i<n;i++){
      	ans=max(ans,st[i]+st2[i]);
      }
      cout<<"Case "<<t+1<<": ";
      cout<<ans<<endl;
   
}
}
