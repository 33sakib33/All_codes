#include<bits/stdc++.h>
using namespace std;
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
int dp[3001][3001];
int LCS(string &s,string &t){
	
	memset(dp,0,sizeof(dp));
	int n=s.size();
	int m=t.size();
	dp[n][m]=0;
	for(int i=n-1;i>=0;i--){
	 	for(int j=m-1;j>=0;j--){
	 		//cout<<i<<" "<<j<<endl;
	 		if(s[i]==t[j]){
	 			dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);	
	 		}
	 		else{
	 			dp[i][j]=max(dp[i][j],dp[i+1][j]);
	 			dp[i][j]=max(dp[i][j],dp[i][j+1]);
	 		}
	 	}
	}
	return dp[0][0];

}
void printpath(queue<int> &st,string &s,string &t){
	int i=0;
	int j=0;
	while(i<s.size() && j<t.size()){
		if(s[i]==t[j]){
			st.push(i);
			i++;
			j++;
		}
		else if(dp[i+1][j]>=dp[i][j+1]){
			i++;
			//cout<<i<<endl;
		}
		else {
		j++;
		//cout<<j<<endl;
		}
		
	}
	
}
void init(){
	string s,t;
	cin>>s>>t;
	ll ans=LCS(s,t);
	queue<int>st;
	printpath(st,s,t);
	/*for(int i=0;i<s.size();i++){
		for(int j=0;j<t.size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//cout<<st.size()<<endl;
	while(!st.empty()){
		cout<<s[st.front()];
		st.pop();
	}
	
	//cout<<ans<<endl;
}
int main(){
	init();
}

