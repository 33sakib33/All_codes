#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	int t=1;
	while(T--){
	int n;
	cin>>n;
	vector<int > a(n+1,0);
	for(int i=1;i<=n;i++){
	 cin>>a[i];
	}
	int cnt=0;
	for(int k=1;k<=n;k++){
	for(int i=1;i<=n;i++){
		if(a[i]==k){
		 if(i!=k){
		  swap(a[i],a[k]);
		  cnt++;
		 }
		}
	}
	}
	cout<<"Case "<<t<<": ";
	cout<<cnt<<endl;
	t++;
	}

}
