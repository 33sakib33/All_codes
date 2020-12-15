#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ff first
#define ss second

#define pll pair<long long, long long>
#define vll vector<long long>

#define vpll vector< pll >
#define flash  ios_base::sync_with_stdio(false); cin.tie(0);




vpll tree(400050,{0,0});
vll a(100007);
ll n;
pll findmax2(pll a,pll b){
	vll x(4);
	x[0]=(a.ff);
	x[1]=(a.ss);
	x[2]=(b.ff);
	x[3]=(b.ss);
	sort(x.rbegin(),x.rend());
	pll ret={x[0],x[1]};
	return ret;
	
}
void build(int node, int left, int right){
	if(left==right){
		tree[node].ff=a[left];
		tree[node].ss=0;
		return;
	}
	ll mid=(left+right)/2;
	build(2*node,left,mid);
	build(2*node+1,mid+1,right);
	tree[node]=findmax2(tree[2*node],tree[2*node+1]);
	
	//cout<<tree[node].ff<<" "<<tree[node].ss<<endl;
	return ;
}
void update(int node,int left,int right,int up,ll x){
	if(up<left || up>right)return;
	if(left==right){
		tree[node].ff=x;
		tree[node].ss=0;
		return ;
	}
	int mid=(left+right)/2;
	update(2*node,left,mid,up,x);
	update(2*node+1,mid+1,right,up,x);
	tree[node]=findmax2(tree[2*node],tree[2*node+1]);
	return ;
	
}
pll query(int node,int left,int right, int ql,int qr){
	
	if(right<ql || left>qr)return {0,0};
	
	
	if(ql<=left && right<=qr){
		return tree[node];
	}
	ll mid=(left+right)/2;
	ll lc=2*node;
	ll rc=2*node+1;
	pll lf=query(lc,left,mid,ql,qr);
	pll rf=query(rc,mid+1,right,ql,qr);
	pll ret= findmax2(lf,rf);
	
	return ret;
}

int main(){
 	flash;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 	}
 	build(1,1,n);
 	
 	ll q;
 	cin>>q;
 	for(int i=0;i<q;i++){
 		char c;
 		int x;
 		ll y1;
 		int y2;
 		cin>>c;
 		
 		if(c=='U'){
 			cin>>x>>y1;
 			update(1,1,n,x,y1);
 		}
 		else if(c=='Q'){
 			cin>>x>>y2;
 			pll qer=query(1,1,n,x,y2);
 			ll ans=qer.ff+qer.ss;
 			cout<<ans<<endl;
 			
 		}
 		//getchar();
 	}
 
}




























