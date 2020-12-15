/*
 ALLAH is Almighty....
*/
#include <bits/stdc++.h>
 
using namespace std;
 
 
#define rep( i, a, n )                    for ( ll i = a; i < n; i++ )
#define per( i, a, n )                    for ( ll i = n - 1; i >= a; i-- )
#define ll                                long long
#define mx                                ( 1000 + 9 )
#define all( x )                          ( x ).begin(), ( x ).end()
 
const ll N = 2005;
 
ll n, m, a, b, c, d, cnt, item;
ll DP[ N ][ N ];
vector < ll > weight, profit;
 
 
ll knapsack( ll need, ll idx )
{
      if ( idx == item )  return 0;
      if ( need == 0 )    return 0;
 
      if ( DP[ need ][ idx ] != -1 )
            return DP[ need ][ idx ];
 
      ll cost1 = 0, cost2;
 
      if ( need >= weight[ idx ] )
            cost1 = profit[ idx ] + knapsack( need - weight[ idx ], idx + 1 );
      cost2 = knapsack( need, idx + 1 );
 
      return DP[ need ][ idx ] = max( cost1, cost2 );
}
 
void construct( ll X, ll W, ll P )
{
      while ( X-- ) {
            weight.push_back( W );
            profit.push_back( P );
      }
}
 
void helpMeBro( )
{
      cin >> n >> m >> c >> d;
 
      cnt = n / c;
      construct( cnt, c, d );
 
      rep( i, 0, m ) {
            cin >> a >> b >> c >> d;
            construct( min(a / b,n/c), c, d );
      }
 
      rep( i, 0, N ) {
            rep( j, 0, N ) {
                  DP[ i ][ j ] = -1;
            }
      }
 
      item = weight.size();
 
      cout << knapsack( n, 0 ) << "\n";
}
 
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
 
      ll t = 1;
      //cin >> t;
 
      rep( i, 0, t )
            helpMeBro();
}
