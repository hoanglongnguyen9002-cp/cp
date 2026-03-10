// https://codeforces.com/group/6iRxenZ3op/contest/676722/problem/A
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 25;
const int INF = 1e18;
int n, k, c[N][N], dp[(1 << N)];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("WAREHOUSE.INP", "r", stdin);
    freopen("WAREHOUSE.OUT", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }

    int MASK = (1 << n) - 1;
    fill(dp, dp + (1 << N), INF);
    dp[MASK] = 0;
    for (int mask = MASK; mask >= 0; --mask) {
        if (__builtin_popcount(mask) >= k && dp[mask] != INF) {
//                cout << -1 << endl;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < n; ++j) {
                        if (i == j) continue;
                        if (mask & (1 << j)) {
                            // i -> j
                            dp[mask ^ (1 << i)] = min(dp[mask ^ (1 << i)], dp[mask] + c[i][j]);
                        }
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int mask = 0; mask <= MASK; ++mask) {
        if (__builtin_popcount(mask) == k) {
            ans = min(ans, dp[mask]);
//            cout << bitset<5>(mask) << ' ' << dp[mask] << '\n';
        }
    }
    cout << ans;
    return 0;
}
