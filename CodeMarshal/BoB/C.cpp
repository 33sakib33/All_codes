#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define cin1(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define ll long long
#define mp make_pair
#define pb push_back
#define nl printf("\n")
#define ff first
#define ss second
#define set0(a) memset ((a), 0 , sizeof(a))
#define set1(a) memset((a),-1,sizeof (a))
#define pi pair<int, int>
#define ps pair<string, string>
#define pl pair<long, long>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vl vector<long>
#define vi vector<int>
#define vs vector<string>
#define vps vector< ps >
#define vpi vector< pi >
#define vpl vector< pl >
#define vpll vector< pll >
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc(t,T) for(long long t=0;t<T;t++)
#define rep(i,s,n,d) for(long long i=s;i<n;i=i+d)
int flag=0;
int prev2=0;
string parse(int n){
	string op;
	int i=0;
	while(n>0){
		op+=((n%10)+'0');
		n/=10;
	}
	
	return op;
}
int diff(string s){
	sort(s.rbegin(),s.rend());
	int choto=0;
	int add=1000;
	int add2=1;
	int j=3;
	int boro=0;
	for(int i=0;i<s.size();i++){
		int adder= s[i]-'0';
		int adder2=s[i]-'0';
		if(adder==0)break;
		choto=choto+adder*add2;
		boro =boro+adder2*add;
				add/=10;
				add2*=10;		
	}
	

	if(boro-choto==0)flag=1;
	return boro-choto;

}

int main(){
 	int T;
 	scanf("%d",&T);
 	flag=0;
 	tc(t,T){
 		int n,k;
 		flag=0;
 		scanf("%d %d",&n,&k);
 		for(int i=0;i<k;i++){
 			string x=parse(n);
 			prev2=n;
 			n=diff(x);	
 			if(prev2==n)break;
 			
 		}
 		printf("%d\n",n);
 	}
}




























