#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 4e18;
const ll NEG_INF = -(ll)9e18;

bool solve(){
    int n; 
    cin >> n;

    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll best_pos = 0;
    ll best_neg = NEG_INF;

    for(int i = 0; i < n; i++){
        ll p = best_pos;
        ll q = best_neg;

        ll red_pos = (p == NEG_INF ? NEG_INF : p - a[i]);
        ll red_neg = (q == NEG_INF ? NEG_INF : q - a[i]);

        ll blue_from_neg = (q == NEG_INF ? NEG_INF : b[i] - q);
        ll blue_from_pos = (p == NEG_INF ? NEG_INF : b[i] - p);

        best_pos = max(red_pos, blue_from_neg);
        best_neg = max(red_neg, blue_from_pos);
    }

    cout << max(best_pos, best_neg) << "\n";
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}
