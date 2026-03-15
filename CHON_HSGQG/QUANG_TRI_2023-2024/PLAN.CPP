#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long INF = 1e18;
const int N = 2e4 + 4;
const int M = 1e3 + 3;

int n, m;
ll y[N], c[N], x[M], v[M], dp[M];
ll pref[M], pref2[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("PLAN.INP", "r", stdin);
    freopen("PLAN.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> y[i] >> c[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x[i] >> v[i];
        pref[i] = pref[i - 1] + v[i];
        pref2[i] = pref2[i - 1] + (v[i] * x[i]);
    }

    fill(dp, dp + M, INF);
    dp[0] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= 1; --j) {
            if (y[j] <= x[i]) {
                int k = lower_bound(x, x + i + 1, y[j]) - x;
                ll cost = (pref2[i] - pref2[k - 1]) - y[j] * (pref[i] - pref[k - 1]);
//                cout << i << ' ' << k << ' ' << cost << '\n';
                dp[i] = min(dp[i], dp[k - 1] + cost + c[j]);
            }
        }

    }

    for (int i = 1; i <= m; ++i) cout << dp[i] << ' ';

    return 0;
}
