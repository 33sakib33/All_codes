#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll    long long

int main() {
    
    vector < ll > type1, type2, type3;
    ll n;
    cin >> n;
    
    for ( int i = 0; i < n; ++i ) {
        int y, w;
        cin >> y >> w;
        if ( w == 1 ) {
            type1.push_back( y );
        }
        else if ( w == 2 ) {
            type2.push_back( y );
        } 
        else {
            type3.push_back( y );
        }
    }
    
    ll q;
    cin >> q;
    sort(type1.begin(),type1.end());
    sort(type2.begin(),type2.end());
    sort(type3.begin(),type3.end());
    while ( q-- ) {
        ll y, w, ans = 0;
        cin >> y >> w;
        
        if ( w == 1 && type1.size() ) {
            ans = upper_bound( type1.begin(), type1.end(), y ) - type1.begin();
        }
        else if ( w == 2 && type2.size() ) {
            ans = upper_bound( type2.begin(), type2.end(), y ) - type2.begin();
        } 
        else if ( w == 3 && type3.size() ) {
            ans = upper_bound( type3.begin(), type3.end(), y ) - type3.begin();
        }
        
        cout << ans << "\n";
    }
    
    
    return 0;
}
