#include<bits/stdc++.h>
using namespace std;
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
int dp[5000][5000];

int LCS(string &s,string &t,int i,int j){
	if(i>=t.size() or j>=s.size()){
		return 0;
	}
	if(dp[i][j]!=-1)return dp[i][j];
	int ln=0;
	if(s[j]==t[i]){
		ln=1+LCS(s,t,i+1,j+1);
		//st.push(i);
	}
	else{
		int ln1=LCS(s,t,i+1,j);
		int ln2=LCS(s,t,i,j+1);
		 ln=max(ln1,ln2);
	}
	dp[i][j]=ln;
	return dp[i][j];

}
void printpath(int i,int j,stack<int> &st,string &s,string &t){
	if(i>=t.size() or j>=s.size())return ;
	if(dp[i][j]==0 || dp[i][j]==-1)return;
	if(t[i]==s[j]){
		printpath(i+1,j+1,st,s,t);
		st.push(i);
	}
	else if(dp[i][j+1]<=dp[i+1][j]){
		printpath(i+1,j,st,s,t);
	}
	else{
		printpath(i,j+1,st,s,t);
	}
	
}
void init(){

	string s,t;
	cin>>s>>t;
	memset(dp,-1,sizeof(dp));
	int ans=LCS(s,t,0,0);
	/*for(int i=0;i<t.size();i++){
		for(int j=0;j<s.size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	stack <int> st;
	printpath(0,0,st,s,t);
	while(!st.empty()){
		cout<<t[st.top()];
		st.pop();
	}
	cout<<endl;
	/*cout<<ans<<endl;*/
	
}
int main(){
	flash;
	init();
}
