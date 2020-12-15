#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define vll vector<long long>

#define flash  ios_base::sync_with_stdio(false); cin.tie(0);

#define lc(x) 2*x
#define rc(x) 2*x+1
vll tree(400050,0);
vll lazy(400050,0);

ll n;
ll c;

void lazyupdate(ll node,ll left,ll right){
	
	//tree[node]=tree[node]+lazy[node]*(right-left+1);
	ll mid=(left+right)/2;
	tree[lc(node)]+=(lazy[node]*(mid-left+1));
	tree[rc(node)]+=(lazy[node]*(right-mid-1+1));
	lazy[lc(node)]+=lazy[node];
	lazy[rc(node)]+=lazy[node];
	lazy[node]=0;
	
}

void build(ll node,ll left,ll right){
	lazy[node]=0;
	if(right==left){
		tree[node]=0;
		return ;
	}
	
	ll mid=(left+right)/2;
	build(lc(node),left,mid);
	build(rc(node),mid+1,right);
	tree[node]=tree[lc(node)]+tree[rc(node)];
}

void update(ll node,ll left,ll right,ll ql,ll qr,ll x){
	
	if(left>qr || right<ql)return ;
	if(ql<=left && right<=qr){
		
		tree[node]+=((x*(right-left+1)));
		lazy[node]+=x;
		return ;
	}
	lazyupdate(node,left,right);
	ll mid=(left+right)/2;
	update(lc(node),left,mid,ql,qr,x);
	update(rc(node),mid+1,right,ql,qr,x);
	tree[node]=tree[lc(node)]+tree[rc(node)];
}

ll query(ll node,ll left,ll right,ll ql,ll qr){

	if(left>qr || right<ql)return 0;
	
	if(ql<=left && right<=qr){
		//lazyupdate(node,left,right);
		return tree[node];
	}
	
	lazyupdate(node,left,right);
	ll mid=(left+right)/2;
	ll s1=query(lc(node),left,mid,ql,qr);
	ll s2=query(rc(node),mid+1,right,ql,qr);
	
	return s1+s2;
}

int main(){
 flash;
 ll T;
 cin>>T;
 while(T--){
 	//tree.clear();
 	//lazy.clear();
 	cin>>n>>c;
 	build(1,1,n);
 	for(int i=0;i<c;i++){
 		ll type;
 		cin>>type;
 		if(type==0){
 			ll p,q,v;
 			cin>>p>>q>>v;
 			update(1,1,n,p,q,v);
 		}
 		else if(type==1){
 			ll p,q;
 			cin>>p>>q;
 			ll ans=query(1,1,n,p,q);
 			cout<<ans<<endl;
 		}
 	}
 	/*for(int i=1;i<4*n;i++){
 		cout<<lazy[i]<<" ";
 		
 	}
 	nl;*/
 	
 	
 }
 return 0;
}




























