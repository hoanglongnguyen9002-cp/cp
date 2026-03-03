// https://codeforces.com/group/6iRxenZ3op/contest/674259/problem/A
#include <bits/stdc++.h>
using namespace std;

#define int long long 
const long long INF = 1e18;
const int N = 2e5 + 5;
int n, x[N], pref[N], suff[N];

long long calc(int idx, int a, int b) {
    // long long res = 0;
    // for (int i = 1; i <= n; ++i) {
    //     if (x[i] <= idx) res += a * (idx - x[i]);
    //     else res += b * (x[i] - idx);
    // }
    return a * (x[idx] * idx - pref[idx]) + b * (suff[idx + 1] - x[idx] * (n - idx));
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("MOONCAKE.INP", "r", stdin);
    freopen("MOONCAKE.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + x[i];
    for (int i = n; i >= 1; --i) suff[i] = suff[i + 1] + x[i];

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        long long ans = INF;
        ans = min(ans, calc((b * n + (a + b) - 1) / (a + b), a, b));
        cout << ans << '\n';
    }

    return 0;
}