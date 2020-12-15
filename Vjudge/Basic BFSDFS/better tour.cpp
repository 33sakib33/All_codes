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

vi gr[50046];
int vis[50046];
int prev1[50046];
int n,m;
void bfs(int s){
 	queue<int> q;
 	q.push(s);
 	prev1[s]=s;
 	vis[s]=1;
 	while(!q.empty()){
 		int s1=q.front();
 		q.pop();
 		for(auto x:gr[s1]){
 			if(vis[x]==0){
 			 q.push(x);
 			 vis[x]=1;
 			 prev1[x]=s1;
 			}
 		}
 	}
}

int main(){
    //freopen("output.txt","w",stdout);
    ll T;
    cin>>T;
    tc(t,T){
        cin>>n;
   
    memset(vis,0,sizeof(vis));
    memset(prev1,0,sizeof(prev1));
    vi city(n+3,0);
   
    for(int i=0;i<n;i++){
    	cin>>city[i];
    }
    for(int i=0;i<n-1;i++){
    	gr[city[i]].pb(city[i+1]);
    	gr[city[i+1]].pb(city[i]);
    }
    for(int i=0;i<n;i++){
    	sort(gr[city[i]].begin(),gr[city[i]].end());
    }
  
    bfs(city[0]);
    int ds=city[n-1];
    stack<int> st;
    st.push(ds);
    while(prev1[ds]!=ds){
    	st.push(prev1[ds]);
    	ds=prev1[ds];
    }
    cout<<"Case "<<t+1<<":\n";
    cout<<st.top();
    
    st.pop();
    while(!st.empty()){
    	cout<<" "<<st.top();
    	st.pop();
    }
     for(int i=0;i<n;i++)gr[city[i]].clear();
    cout<<endl;
}
}


















