#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(int d, ll x) {
    for (ll i = d; i * i <= x; ++i) {
        if(x % i == 0) return calc(i, x / i);
    }
    return x - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRACSEQ.INP", "r", stdin);
    freopen("FRACSEQ.OUT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << calc(2, x * x * x + 1ll) << '\n';
    }
    return 0;
}
