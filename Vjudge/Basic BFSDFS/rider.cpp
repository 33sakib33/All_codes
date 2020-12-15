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
char s[14][14];
int vis[14][14];
int dis[14][14];
   int cnt=0;
   int flg=0;
int bfs(int i,int j,int m,int n){
 queue<pi> q;
 q.push({i,j});
 vis[i][j]=1;
 dis[i][j]=0;
 int sum1=0;
     int cnt2=0;
 while(!q.empty()){
    pi p=q.front();
    q.pop();
    int x=p.ff;
    int y=p.ss;
    if(s[x][y]!='.'){
            int dsx=s[x][y]-'0';
            int tod;
            if(dsx>=dis[x][y]){
                tod=1;
            }
            else tod=(dis[x][y]+dsx-1)/dsx;
            if(dis[x][y]==0)tod=0;
        sum1=sum1+tod;

        cnt2++;
        if(cnt2==cnt)break;
    }
    for(int itr1=0;itr1<8;itr1++){
        int x1=x+todx[itr1];
        int y1=y+tody[itr1];
        if(min(x1,y1)<0 || x1>=m || y1>=n){
            continue;
        }
        if(vis[x1][y1]==0){
            vis[x1][y1]=1;
            dis[x1][y1]=dis[x][y]+1;
            q.push({x1,y1});

        }
    }
 }
/*for(int i1=0;i1<m;i1++){
    	for(int j1=0;j1<n;j1++){
    	 cout<<dis[i1][j1]<<" ";
    	  }
    	  cout<<endl;
    	  }
     cout<<endl;
    for(int i1=0;i1<m;i1++){
    	for(int j1=0;j1<n;j1++){
    	 cout<<vis[i1][j1]<<" ";
    	  }
    	  cout<<endl;
    	  }
    cout<<endl;
    cout<<endl;*/
 if(cnt!=cnt2){
        sum1=INT_MAX;
        
 }
 else flg=1;
return sum1;
}

int main(){
    freopen("output.txt","w",stdout);
    ll T;
    cin>>T;
    tc(t,T){
        int n,m;
        cin>>m>>n;
        getchar();
        cnt=0;
        flg=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>s[i][j];
                if(s[i][j]!='.')cnt++;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               
                ans=min(ans,bfs(i,j,m,n));
                memset(vis,0,sizeof(vis));
                memset(dis,0,sizeof(dis));
            }
        }
        if(flg==0)ans=-1;
    cout<<"Case "<<t+1<<": ";
    cout<<ans<<endl;
   
}
}
