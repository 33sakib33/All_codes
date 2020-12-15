#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll q;
		cin>>q;
		vll a(n+7,0);
		priority_queue pq;
		vector<pair<ll,ll>> checker(q+7,{0,0});
		for(int i=0;i<q;i++){
			ll x,add;
			cin>>x>>add;
			a[x]+=add;
			pq.push(a[x]);
			checker[i]={i,pq.front()};
		}
	}
	ll ans=0;
	if(q==1){
		ans=0;
	}
	else{
	for(int i=q-2;i>=2;i--){
		if(checker[i].second!=checker[i+1]{
			ans=i+1;
		}
	}
	}
	cout<<ans<<endl;

}
