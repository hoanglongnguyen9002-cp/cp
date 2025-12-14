#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
const int MASK = (1 << 10);
const int INF = INT_MAX;
const int BAD = (1 << 1) | (1 << 8) | (1 << 9);
map<int,int> mp;
pair<int,int> a[N];
int dp[N][MASK];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEQ198.INP", "r", stdin);
    freopen("SEQ198.OUT", "w", stdout);
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int n = 0   ;
    for (pair<int,int> tmp : mp) a[++n] = tmp;
    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < MASK; ++mask) {
            dp[i][mask] = -INF;
        }
    }
    dp[1][0] = 0;
    dp[1][1] = a[1].second;
    for (int i = 1; i < n; ++i) {
        for (int mask = 0; mask < MASK; ++mask) {
            if (dp[i][mask] == -INF) continue;
            int diff = a[i + 1].first - a[i].first;
            int new_mask = (diff >= 10 ? 0 : (mask << diff) & (MASK - 1));
            dp[i + 1][new_mask] = max(dp[i + 1][new_mask], dp[i][mask]);
            if ((new_mask & BAD) == 0) dp[i + 1][new_mask | 1] = max(dp[i + 1][new_mask | 1], dp[i][mask] + a[i + 1].second);
        }
    }
    int mx = 0;
    for (int mask = 0; mask < MASK; ++mask) mx = max(mx, dp[n][mask]);
    cout << m - mx;
    return 0;
}
