#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define vll vector<long long>

#define flash  ios_base::sync_with_stdio(false); cin.tie(0);

#define lc(x) 2*x
#define rc(x) 2*x+1
const ll mod=100000000000000000;
vll tree(800100,mod);
vll lazy(800100,0);
vll arr(200007,0);
ll n;
ll q;

void lazyupdate(ll node,ll left,ll right){
	
	//tree[node]=tree[node]+lazy[node]*(right-left+1);
	ll mid=(left+right)/2;
	tree[lc(node)]+=(lazy[node]);
	tree[rc(node)]+=(lazy[node]);
	lazy[lc(node)]+=lazy[node];
	lazy[rc(node)]+=lazy[node];
	lazy[node]=0;
	
}

void build(ll node,ll left,ll right){
	lazy[node]=0;
	if(right==left){
		tree[node]=arr[left];
		return ;
	}
	
	ll mid=(left+right)/2;
	build(lc(node),left,mid);
	build(rc(node),mid+1,right);
	tree[node]=min(tree[lc(node)],tree[rc(node)]);
}

void update(ll node,ll left,ll right,ll ql,ll qr,ll x){
	
	if(left>qr || right<ql)return ;
	if(ql<=left && right<=qr){
		
		tree[node]+=(x);
		lazy[node]+=x;
		return ;
	}
	lazyupdate(node,left,right);
	ll mid=(left+right)/2;
	update(lc(node),left,mid,ql,qr,x);
	update(rc(node),mid+1,right,ql,qr,x);
	tree[node]=min(tree[lc(node)],tree[rc(node)]);
}

ll query(ll node,ll left,ll right,ll ql,ll qr){

	if(left>qr || right<ql)return mod;
	
	if(ql<=left && right<=qr){
		//lazyupdate(node,left,right);
		return tree[node];
	}
	
	lazyupdate(node,left,right);
	ll mid=(left+right)/2;
	ll s1=query(lc(node),left,mid,ql,qr);
	ll s2=query(rc(node),mid+1,right,ql,qr);
	
	return min(s1,s2);
}

int main(){
	
	flash;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	
	cin>>q;
	
	for(int i=0;i<q;i++){
	ll a,b,c;
	cin>>a>>b;
	if(cin.get()==10){
	
	
		ll ans1,ans2;
		ans1=ans2=mod;
		if(b<a){
		 ans1=query(1,1,n,a+1,n);
		 ans2=query(1,1,n,1,b+1);
		}
		else ans1=query(1,1,n,a+1,b+1);
		cout<<min(ans1,ans2)<<endl;
	}
	else{
		cin>>c;
		if(b<a){
		 update(1,1,n,a+1,n,c);
		 update(1,1,n,1,b+1,c);
		}
		else update(1,1,n,a+1,b+1,c);
	}
	
	}
	/*for(int i=1;i<4*n;i++){
		cout<<lazy[i]<<" ";
		
	}
	nl;*/
	return 0;
}




























