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
 	ll n,m;
 	cin>>n>>m;
 	vll a(n+1,0);
 	vll w(m,0);
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 		
 	}
 	for(int i=0;i<m;i++)cin>>w[i];
 	sort(a.begin(),a.end());
 	ll s1=0;
 	ll s2=0;
 	vll sum1(n,0);
 	for(int i=0;i<n;i+=2){
 		s1+=a[i];
 		sum1[i]+=a[i];
 		if(i-2>=0){
 			sum1[i]+=sum1[i-2];
 		}
 	}
 	for(int i=1;i<n;i+=2){
 		s2+=a[i];
 		sum1[i]+=a[i];
 		if(i-2>=0){
 			sum1[i]+=sum1[i-2];
 		}
 	}
 	ll ans=LONG_MAX;
 	for(int i=0;i<m;i++){
 		std::vector<ll>::iterator low1;
 		low1= lower_bound(a.begin(),a.end(),w[i]);
 		ll pos=low1-a.begin();
 		ll temp1,temp2;
 		
 		temp1=s1;
 		temp2=s2;
 		cout<<pos<<endl;
 		if(pos%2==0){
 			continue;
 			if((pos-2)>=0){
 				temp1+=sum1[pos-2];
 			}
 			temp1-=sum1[n-1];
 			temp1+=w[i];
 			if(pos-1>=0){
 				temp1-=sum1[pos-1];
 			}
 			
 			temp1+=sum1[n-2];
 			if(pos-2>=0){
 				temp2-=sum1[pos-2];
 			}
 			temp2+=sum1[n-1];
 			if(pos-1>=0){
 				temp2+=sum1[pos-1];
 			}
 			temp2-=sum1[n-2];
 			ans=min(ans,temp2-temp1);
 			cout<<temp2-temp1<<endl;
 		}
 		else{
 			temp2+=w[i];
 			ans=min(ans,abs(temp2-temp1));
 			//cout<<temp2-temp1<<endl;
 		}
 		
 	}
 	cout<<ans<<endl;
}




























