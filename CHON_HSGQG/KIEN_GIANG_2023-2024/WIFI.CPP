// https://codeforces.com/group/6iRxenZ3op/contest/674696/problem/B
#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 2e5 + 5;
int n, k, dp[N][2], node[N * 4];
string s;

void upd(int id, int l, int r, int pos, int val) {
    if (l == r) {
        node[id] = val;
        return; 
    }
    int mid = (l + r) / 2;
    if (pos <= mid) upd(id * 2, l, mid, pos, val);
    else upd(id * 2 + 1, mid + 1, r, pos, val);
    node[id] = min(node[id * 2], node[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return LLONG_MAX;
    if (u <= l && r <= v) return node[id];
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("WIFI.INP", "r", stdin);
    freopen("WIFI.OUT", "w", stdout);

    cin >> n >> k >> s;
    s = ' ' + s;

    fill(node, node + 4 * N, LLONG_MAX);

    for (int i = 0; i < N; ++i) {
        dp[i][0] = dp[i][1] = LLONG_MAX;
    }
    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i <= n; ++i) {        
        dp[i][0] = min(dp[i][0], get(1, 1, n, max(1ll, i - k), i - 1));
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + i;
        if (s[i] == '1') {
            dp[i][1] = min(dp[max(0ll, i - k - 1)][1], dp[max(0ll, i - k - 1)][0]) + i;
            upd(1, 1, n, i, dp[i][1]);
        } 
    }
    // for (int i = 1; i <= n; ++i) cout << dp[i][0] << ' ';cout << endl;
    // for (int i = 1; i <= n; ++i) cout << dp[i][1] << ' ';cout << endl;
    cout << min(dp[n][1], dp[n][0]);
    return 0;
}