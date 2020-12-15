#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);


int main(){
	flash;
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll q;
		cin>>q;
		vector<ll> a(n+7,0);
		set<pair<ll,ll>> pq;
		for(int i=1;i<=n;i++){
			pq.insert({a[i],-i});
		}
		vector<pair<ll,ll>> chk(q+7,{0,-1});
		
		for(int i=1;i<=q;i++){
			ll x,add;
			cin>>x>>add;
			pq.erase({a[x],-x});
			a[x]+=add;
			
			pq.insert({a[x],-x});
			
			pair<ll,ll> temp = *pq.rbegin();
			chk[i].first=temp.first;
			chk[i].second=temp.second;
		}
	
	ll ans=0;
	if(q==1){
		pair<ll,ll> temp = *pq.rbegin();
		if(temp.second==-1)ans=0;
		else ans=1;	
	
	}
	else{
	for(int i=q;i>=1;i--){
		
		if(chk[i].second!=chk[i-1].second){
			ans=i;
			
			
			break;
		}
	}
	if(chk[1].second==-1 && ans==1){
		//ans=0;	
	}
	/*for(auto x:pq)cout<<x.first<<" "<<x.second<<endl;
	for(int i=0;i<q;i++){
	cout<<chk[i].first<<" "<<chk[i].second<<endl;
	}*/
	}
	cout<<ans<<endl;
	}

}
