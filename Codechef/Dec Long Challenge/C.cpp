#include<bits/stdc++.h>
using namespace std;

#define ll long long



int main(){
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll d;
		cin>>d;
		ll risk,notrisk;
		risk=notrisk=0;
		for(int i=0;i<n;i++){
			ll temp;
			cin>>temp;
			if(temp>=80 || temp<=9)risk++;
			else notrisk++;
		}
		
		ll ans=( (risk+d-1)/d) +( (notrisk+d-1)/d);
		cout<<ans<<endl;
	}

}




























