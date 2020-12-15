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
ll n;
ll array[100007];
ll tree[4*100007];
void build(int node,int left ,int right){
	if(left==right){
		tree[node]=a[left];
		return ;
	}
	int mid=(left+right)/2;
	build(2*node,left,mid);
	build(2*node+1,mid+1,right);
	tree[node]= tree[2*node]+tree[2*node+1];
}
void update(int node,int left,int right,int index, int x){ //1-7
	
	if(index<left || index>right)return ;
	if(left==right){
		tree[node]+=x;
		return ;
	}
	int mid=(left+right)/2;
	build(2*node,left,mid,index,x); 5,5
	build(2*node+1,mid+1,right,index,x);7,7
	tree[node]= tree[2*node]+tree[2*node+1];
}
ll query(int node,int left,int right,int qleft, int qright ){
	if(left>qright || right<qleft)return 0;
	if(qleft<=left && right<=qright)return tree[node];
	int mid= (left+right)/2;
	ll q1=query(2*node,left,mid,qleft,qright);
	ll q2=quert(2.node+1,mid+1,right,qleft,qright);
	return q1+q2;

}

int main(){
 	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x==1){
			update(1,1,n,y,z);
		}
		else if(x==2){
			cout<<query(1,1,n,y,z);
		}
	}
	
}




























