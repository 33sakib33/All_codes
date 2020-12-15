#include<bits/stdc++.h>
using namespace std;

#define ll long long



int main(){
	ll T;
	cin>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		int f=1;
		ll cnt=0;
		ll pls=0;
		if(k==n){
		for(int i=1;i<=n;i++){
		 	cout<<i<<" ";
		}
		}
		else{
		 for(int i=1;i<=n;i++){
		 	if(cnt==k){
		 	cout<<-1*i<<" ";
		 	}
		 	else if(n-i+1==k-cnt){
		 	cout<<i<<" ";
		 	cnt++;
		 	}
		 	else{
		 	cout<<f*i<<" ";
		 	if(f==1)cnt++;
		 	f=f*-1;
		 	}
		 	//cout<<cnt<<" "<<i<<endl;
		 }
		}
		cout<<endl;
	}

}




























