#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define vll vector<long long>

#define flash  ios_base::sync_with_stdio(false); cin.tie(0);

#define lc(x) 2*x
#define rc(x) 2*x+1
vll tree(800050,0);
//vll lazy(400050,0);
vll arr(200007,0);

 ll n,k,q;
/*void lazyupdate(ll node,ll left,ll right){
	
	//tree[node]=tree[node]+lazy[node]*(right-left+1);
	ll mid=(left+right)/2;
	tree[lc(node)]+=(lazy[node]*(mid-left+1));
	tree[rc(node)]+=(lazy[node]*(right-mid-1+1));
	lazy[lc(node)]+=lazy[node];
	lazy[rc(node)]+=lazy[node];
	lazy[node]=0;
	
}
*/
void build(ll node,ll left,ll right){
	
	if(right==left){
		if(arr[left]>=k)
		tree[node]=1;
		else tree[node]=0;
		return ;
	}
	
	ll mid=(left+right)/2;
	build(lc(node),left,mid);
	build(rc(node),mid+1,right);
	
	tree[node]=tree[lc(node)]+tree[rc(node)];
	
}

/*void update(ll node,ll left,ll right,ll ql,ll qr,ll x){
	
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
*/
ll query(ll node,ll left,ll right,ll ql,ll qr){

	if(left>qr || right<ql)return 0;
	
	if(ql<=left && right<=qr){
		//lazyupdate(node,left,right);
		return tree[node];
	}
	
	//lazyupdate(node,left,right);
	ll mid=(left+right)/2;
	ll s1=query(lc(node),left,mid,ql,qr);
	ll s2=query(rc(node),mid+1,right,ql,qr);
	
	return s1+s2;
}

int main(){
 flash;

 cin>>n>>k>>q;

 ll max1=0;
 ll min1=10e9;
 for(int i=0;i<n;i++){
 	ll a,b;
 	cin>>a>>b;
 	arr[a]++;
 	arr[b+1]--;
 	max1=max(max1,b);
 	min1=min(min1,a);
 }
 
 for(int i=min1+1;i<=max1;i++){
 	arr[i]+=arr[i-1];
 }  /*for(int i=min1;i<=max1;i++){
 	cout<<arr[i]<<" ";
 }*/
 vll carr(200007,0);
 for(int i=min1;i<=max1+9;i++){
 	if(arr[i]>=k)carr[i]=1;
 }
  for(int i=1;i<=200000;i++){
 	carr[i]+=carr[i-1];
 }
  
  for(int i=0;i<q;i++){
  	ll ql,qr;
  	cin>>ql>>qr;
  	ll ans=carr[qr]-carr[ql-1];
  	cout<<ans<<endl;
  }
 return 0;
}




























