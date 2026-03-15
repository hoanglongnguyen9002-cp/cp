#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k, p, m;
        cin >> n >> k >> p >> m;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ll cost = a[p];
        vector<ll> x;
        for (int i = 1; i <= n; ++i) if (i != p) x.push_back(a[i]);
        sort(x.begin(), x.end());
        if (p > k) {
            vector<int> pre;
            for (int i = 1; i < p; ++i) pre.push_back(a[i]);
            sort(pre.begin(), pre.end());
            ll cost1 = 0;
            for (int i = 0; i < p - k; ++i) cost1 += pre[i];
            m -= cost1;
        }
        if (m < cost) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = 1;
        m -= cost;
        ll cycle = 0;
        for (int i = 0; i < n - k; ++i) cycle += x[i];
        ll check = cycle + cost;
        if (check > 0) ans += m / check;
        cout << ans << '\n';
    }
    return 0;
}
