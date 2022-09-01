#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1e9+7;

ll mod(ll x) {
    return (((x%M)+M)%M);
}

ll mult( ll a, ll b) {
    return (mod(mod(a) * mod(b)));
}

ll add( ll a, ll b) {
    return (mod(mod(a) + mod(b)));
}

ll power(ll x, ll y) {
    if( x == 0)
        return 0;
    
    if( y == 0)
        return 1LL;
    
    if( y == 1)
        return mod(x);

    ll res = 1;

    while(y) {
        if(y % 2 != 0) {
            res = mult(res, x);
        }
        x = mult(x, x);
        y = y/2;
    }

    return mod(res);
}

ll pow(ll x, ll n) {
    if(n == 0)
        return 1LL;
    
    if(n == 1) 
        return mod(x);
    
    if(n == -1)
        return mod(1/x);
    
    ll temp = mod(pow(x, n/2));

    if(n%2 == 0)
        return mod(mult(temp, temp));

    if(x  > 0)
        return mod(mult(temp, mod(mult(temp, x)))); 
    
    else 
        return mod(mult(temp, mod(mult(temp, 1/x))));
}

void solve() {
    int n=5;

    vector<ll> arr(n, 2);
    vector<ll> prefix(n+1, 0);
    
    for(int i=n-1; i>=0; i--) {
        prefix[i] = prefix[i+1] + arr[i];   
    }

    ll res = 0;

    for(int i=0; i<n; i++) {
        res = add(res, mult(prefix[i+1], arr[i]));
    }

    cout<< res;
}


int main() {
    cout << "HI \n" << mult(555, 55) << "\n" << add(8,7);

    return 0;
}