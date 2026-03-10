// https://codeforces.com/group/6iRxenZ3op/contest/676722/problem/B
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int N = (1 << 10);
int n, x, y, dp[N], cur[N];
struct Stones {
    int a;
    vector<int> b;
    bool operator < (const Stones &other) const {
        return a > other.a;
    }
};
vector<Stones> stones;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("JEWELRY.INP", "r", stdin);
    freopen("JEWELRY.OUT", "w", stdout);

    cin >> n >> x >> y;
    stones.resize(n);
    for (int i = 0; i < n; ++i) cin >> stones[i].a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < x; ++j) {
            int val;
            cin >> val;
            stones[i].b.push_back(val);
        }
    }
    sort(stones.begin(), stones.end());

    int MASK = (1 << x) - 1;
    fill(dp, dp + N, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        Stones val = stones[i];
        fill(cur, cur + N, -INF);
        for (int mask = 0; mask <= MASK; ++mask) {
            if (dp[mask] == -INF) continue;
//            cur[mask] = max(cur[mask], dp[mask] + val.a);
            int cnt = __builtin_popcount(mask);
            if (i - cnt < y) cur[mask] = max(cur[mask], dp[mask] + val.a);
            else cur[mask] = max(cur[mask], dp[mask]);

            for (int j = 0; j < x; ++j) {
                if (!(mask & (1 << j))) {
                    int nx = mask | (1 << j);
                    cur[nx] = max(cur[nx], dp[mask] + val.b[j]);
                }
            }
        }
        copy(cur, cur + N, dp);
    }
    cout << dp[MASK];
    return 0;
}
