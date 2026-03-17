#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int md = 1e9 + 7;
const int N = 4e5 + 5;

ll fac[N], inv[N];

ll mul(ll a, ll b) {
    return (a * b) % md;
}

ll power(ll a, ll b) {
    if (b == 0) return 1;
    if (b & 1) return mul(a, power(a, b - 1));
    ll x = power(a, b / 2);
    return mul(x, x);
}

ll C(ll k, ll n) {
    return mul(mul(fac[n], inv[k]), inv[n - k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("IDENT.INP", "r", stdin);
    freopen("IDENT.OUT", "w", stdout);
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = power(fac[N - 1], md - 2);
    for (int i = N - 2; i >= 0; --i) inv[i] = mul(inv[i + 1], i + 1);
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int n, k;
        cin >> n >> k;
        cout << C(n, n + k - 1) << '\n';
    }
    return 0;
}
