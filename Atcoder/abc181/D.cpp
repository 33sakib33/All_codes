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

#define meax 10000001
vll spf(meax,0);
void siv(){
    spf[1]=1;

   for(ll i=2;i<meax;i++)spf[i]=i;

   for(ll i=4;i<meax;i+=2){
        spf[i]=2;
    }
    for(ll i=3;i*i<meax;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<meax;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}



int main(){
 	string s;
 	cin>>s;
	ll n;
	n=s.size();
	ll flag=-1;
	if(n==1){
		if(s[0]=='8')flag=1;
	}
	if(n==2){
		ll cnt=0;
		ll a=(s[0]-'0')*10+ (s[1]-'0');
		if(a%8==0)flag=1;
		 a=(s[1]-'0')*10+ (s[0]-'0');
		 if(a%8==0)flag=1;
		
	}
	else{
		for(int i=13;i<=1000/8;i++){
			ll d=i*8;
			string s1(3,'p');
			s1[0]=(d%10+'0');
			d=d/10;
			s1[1]=(d%10+'0');
			d=d/10;
			s1[2]=(d%10+'0');
			ll cnt=0;
			vll flag1(n,0);
			vll flag2(3,0);
			for(int j=0;j<n;j++){
				if(s1[0]==s[j] && flag2[0]==0 && flag1[j]==0){
					cnt++;
					flag1[j]=1;
					flag2[0]=1;
				}
				
				if(s1[1]==s[j] && flag2[1]==0 && flag1[j]==0){
					cnt++;
					flag1[j]=1;
					flag2[1]=1;
				}
				if(s1[2]==s[j] && flag2[2]==0 && flag1[j]==0){
					cnt++;
					flag1[j]=1;
					flag2[2]=1;
				}
				if(cnt==3)flag=1;
				if(flag==1)break;
			}
			if(flag==1)break;
		}
	}
	if(flag==1)cout<<"Yes\n";
	else cout<<"No\n";
	
}




























