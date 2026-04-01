#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int md = 1e9;
const int N = 1005;
int n, m, k, q;
bool bad[N][N];
int dx[4] = {1, -1, 2, 2};
int dy[4] = {2, 2, 1, -1};
ll dp[N][N];

bool invalid(int x, int y) {
    return (x < 0 || x > n || y < 0 || y > m || bad[x][y]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SOCACH.INP", "r", stdin);
    freopen("SOCACH.OUT", "w", stdout);
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        bad[x][y] = true;
    }
    dp[n][m] = 1;
    for (int d = n + m - 1; d >= 2; --d) {
        for (int i = max(1, d - m); i <= min(n, d - 1); ++i) {
            int  j = d - i;
            if (invalid(i, j)) continue;
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if (invalid(i, j)) continue;
                dp[i][j] += dp[x][y];
                if (dp[i][j] >= md) dp[i][j] -= md;
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << dp[x][y] << '\n';
    }
    return 0;
}
