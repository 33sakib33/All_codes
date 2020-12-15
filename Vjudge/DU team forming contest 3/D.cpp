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
const int todx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
const int tody[] = { -1,  1, -2,  2, -2,  2, -1,  1 };
bool sortbysec(const pll &a,
              const pll &b)
{
    return (a.second < b.second);
}
/*bool cxp pair<ll, pll> &a,
              const pair<ll, pll> &b)
{
    return (a.ff < b.ff);
}*/

void func(void)
{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
void printStack(stack<string> s){
    if(s.empty())return;

    string x=s.top();
    s.pop();
    printStack(s);
    cout<<x;
    s.push(x);

}


ll binaryexp(ll n,ll p){

    if(p==0) return 1;
    if(p%2==0) return binaryexp((n%mod)*(n%mod),p/2);
    else return ((n%mod)*binaryexp(((n%mod)*(n%mod))%mod,(p-1)/2)%mod);

}

ll flag;


int main(){
 	string s1,s2;
 	cin>>s1>>s2;
 	flag=-1;
 	ll s1s=s1.size();
 	ll s2s=s2.size();
 	ll st=0;
 	for(ll i=0;i<min(s1s,s2s);i++){
		if(s1[i]>='1' && s1[i]<='9'){
			st=i;
			break;
		} 	
		if(s1[i]>s2[i]){
			flag=1;
			break;			
		}
		else if(s1[i]<s2[i]){
			flag=2;
			break;
		}
	}
	if(s1s>s2s && flag==-1){
		flag=1;
	}
	else if(s1s<s2s && flag==-1){
		flag=2;
	}
	else{
		for(ll i=st;i<min(s1s,s2s);i++){
			if(s1[i]>s2[i]){
				flag=1;
				break;
			}
			else if(s1[i]<s2[i]){
				flag=2;
				break;
			}
		}
	}
	if(flag==-1)cout<<"=\n";
	else if(flag==1)cout<<">\n";
	else if(flag==2)cout<<"<\n";
}




























