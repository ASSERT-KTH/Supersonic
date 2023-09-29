#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll b_pow(ll base, ll power){
    ll result = 1;
    while(power){
        if(power & 1) result *= base;
        base *= base;
        power >>= 1;
    }
    return result;
}

int main() {
    ll z;
    while(cin >> z && z){
        ll ans = 0;
        ll z_cubed = b_pow(z, 3);
        for(ll x = 1; b_pow(x, 3) <= z_cubed; ++x){
            for(ll y = x; b_pow(x, 3) + b_pow(y, 3) <= z_cubed; ++y){
                ans = max(ans, b_pow(x, 3) + b_pow(y, 3));
            }
        }
        cout << z_cubed - ans << endl;
    }
    return 0;
}