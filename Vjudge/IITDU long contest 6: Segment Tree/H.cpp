#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ff first
#define ss second

#define pll pair<long long, long long>
#define vll vector<long long>

#define vpll vector< pll >
#define flash  ios_base::sync_with_stdio(false); cin.tie(0);
#define lc(x) 2*x
#define rc(x) 2*x+1
vpll tree(800050,{-100000000000,100000000000});
vpll a(200007);
ll n,q;

void build(ll node, ll left, ll right){
	if(left==right){
		tree[node].ff=a[left].ff;
		tree[node].ss=a[left].ss;
		return;
	}
	ll mid=(left+right)/2;
	build(2*node,left,mid);
	build(2*node+1,mid+1,right);
	ll max1=max(tree[lc(node)].ff,tree[rc(node)].ff);
	ll min1=min(tree[lc(node)].ss,tree[rc(node)].ss);
	tree[node].ff=max1;
	tree[node].ss=min1;
	return ;
}
void update(ll node,ll left,ll right,ll up,ll x,ll y){
	if(up<left || up>right)return;
	if(left==right){
		tree[node].ff=x;
		tree[node].ss=y;
		return ;
	}
	ll mid=(left+right)/2;
	update(2*node,left,mid,up,x,y);
	update(2*node+1,mid+1,right,up,x,y);
	ll max1=max(tree[lc(node)].ff,tree[rc(node)].ff);
	ll min1=min(tree[lc(node)].ss,tree[rc(node)].ss);
	pll var= {max1,min1};
	tree[node]=var;
	return ;
	
}
pll query(ll node,ll left,ll right, ll ql,ll qr){
	
	if(right<ql || left>qr)return {-100000000000,100000000000};
	
	
	if(ql<=left && right<=qr){
		return tree[node];
	}
	ll mid=(left+right)/2;
	pll lf=query(lc(node),left,mid,ql,qr);
	pll rf=query(rc(node),mid+1,right,ql,qr);
	ll max1=max(lf.ff,rf.ff);
	ll min1=min(lf.ss,rf.ss);
	pll var= {max1,min1};
	
	return var;
}

int main(){
 	flash;
 	cin>>n>>q;
 	for(int i=1;i<=n;i++){
 		cin>>a[i].ff;
 		cin>>a[i].ss;
 	}
 	build(1,1,n);
 	
 	
 	
 	
 	for(int i=0;i<q;i++){
 		char c;
 		ll pos;
 		ll le;
 		ll ri;
 		cin>>c;
 		
 		if(c=='C'){
 			cin>>pos>>le>>ri;
 			update(1,1,n,pos,le,ri);
 		}
 		else if(c=='?'){
 			cin>>le>>ri;
 			pll qer=query(1,1,n,le,ri);
 			
 			ll ans=qer.ss-qer.ff+1;
 			if(ans<0)ans=0;
 			cout<<ans<<endl;	
 			
 		}
 		//getchar();
 	}
 
}




























