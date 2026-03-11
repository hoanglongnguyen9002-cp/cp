#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long md = 1e9 + 7;
const int N = 4e6 + 5;
int n, a, b;
ll fac[N], inv[N], D[N];

ll mul(ll a, ll b) {
    return (a * b) % md;
}

ll add(ll a, ll b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

ll power(ll a, ll b) {
    if (b == 0) return 1;
    if (b & 1) return mul(a, power(a, b - 1));
    ll x = power(a, b / 2);
    return mul(x, x);
}

ll C(int k, int n) {
    if (k > n || k < 0) return 0;
    return mul(mul(fac[n], inv[k]), inv[n - k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("MATCH.INP", "r", stdin);
    freopen("MATCH.OUT", "w", stdout);

    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = power(fac[N - 1], md - 2);
    for (int i = N - 2; i >= 0; --i) inv[i] = mul(inv[i + 1], (i + 1));
    D[0] = 1;
    D[1] = 0;
    for (int i = 2; i < N; ++i) D[i] = mul(i - 1, add(D[i - 1], D[i - 2]));

    cin >> n >> a >> b;
    ll ans = 0;
    for (int i = a; i <= b; ++i) ans = add(ans, mul(C(i, n), D[n - i]));
    cout << ans;

    return 0;
}
