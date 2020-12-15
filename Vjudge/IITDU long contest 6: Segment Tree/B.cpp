#include<bits/stdc++.h>
using namespace std;

#define ll int

#define vll vector<long long>

#define flash  ios_base::sync_with_stdio(false); cin.tie(0);

#define lc(x) 2*x
#define rc(x) 2*x+1
typedef struct thr33{
	ll one;
	ll two;
	ll zero;
	ll lazy;

}oh;

oh tree[400050];
//vll tree(400050,0);
//vll lazy(400050,0);

ll n;
ll q;
void sum(ll node){
	tree[node].one=tree[lc(node)].one+tree[rc(node)].one;
	tree[node].two=tree[lc(node)].two+tree[rc(node)].two;
	tree[node].zero=tree[lc(node)].zero+tree[rc(node)].zero;
}

void spUpdate(ll node,ll left,ll right,ll x){
	ll temp1=tree[node].one;
	ll temp2=tree[node].two;
	ll temp0=tree[node].zero;
	
	
	if((x)%3==2){
		tree[node].zero=temp1;
		tree[node].one=temp2;
		tree[node].two=temp0;
	}
	if((x)%3==1){
		tree[node].zero=temp2;
		tree[node].one=temp0;
		tree[node].two=temp1;
	}
	if((x)%3==0){
		tree[node].zero=temp0;
		tree[node].one=temp1;
		tree[node].two=temp2;
	}
}
void lazyupdate(ll node,ll left,ll right){
	
	//tree[node]=tree[node]+lazy[node]*(right-left+1);
	ll mid=(left+right)/2;
	spUpdate(lc(node),left,mid,tree[node].lazy);
	spUpdate(rc(node),mid+1,right,tree[node].lazy);
	tree[lc(node)].lazy+=tree[node].lazy;
	tree[rc(node)].lazy+=tree[node].lazy;
	tree[node].lazy=0;
	
}

void build(ll node,ll left,ll right){
	tree[node].lazy=0;
	if(right==left){
		tree[node].one=0;
		tree[node].two=0;
		tree[node].zero=1;
		return ;
	}
	
	ll mid=(left+right)/2;
	build(lc(node),left,mid);
	build(rc(node),mid+1,right);
	sum(node);
}

void update(ll node,ll left,ll right,ll ql,ll qr,ll x){
	
	if(left>qr || right<ql)return ;
	if(ql<=left && right<=qr){
		
		spUpdate(node,left,right,x);
		tree[node].lazy+=x;
		return ;
	}
	lazyupdate(node,left,right);
	ll mid=(left+right)/2;
	update(lc(node),left,mid,ql,qr,x);
	update(rc(node),mid+1,right,ql,qr,x);
	sum(node);
}

ll query(ll node,ll left,ll right,ll ql,ll qr){

	if(left>qr || right<ql){
		return 0;
	}
	
	if(ql<=left && right<=qr){
		//lazyupdate(node,left,right);
		return tree[node].zero;
	}
	
	lazyupdate(node,left,right);
	ll mid=(left+right)/2;
	ll s1=query(lc(node),left,mid,ql,qr);
	ll s2=query(rc(node),mid+1,right,ql,qr);
	ll yo=s1+s2;
	return yo;
}

int main(){
 flash;
 
 	//tree.clear();
 	//lazy.clear();
 	cin>>n>>q;
 	build(1,1,n);
 	for(int i=0;i<q;i++){
 		ll type;
 		cin>>type;
 		if(type==0){
 			ll p,q;
 			cin>>p>>q;
 			update(1,1,n,p+1,q+1,1);
 		}
 		else if(type==1){
 			ll p,q;
 			cin>>p>>q;
 			ll ans=query(1,1,n,p+1,q+1);
 			cout<<ans<<endl;
 		}
 	}
 	/*for(int i=1;i<4*n;i++){
 		cout<<lazy[i]<<" ";
 		
 	}
 	nl;*/
 	
 	
 
 return 0;
}




























