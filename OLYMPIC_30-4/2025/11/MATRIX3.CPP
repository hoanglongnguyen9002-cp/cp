#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 2100;
int n, m, a[N][N], dp[N][N][3];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("MATRIX3.INP", "r", stdin);
    freopen("MATRIX3.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -INF;
        }
    }
    dp[1][1][0] = a[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j + 1 <= m) dp[i][j + 1][0] = max(dp[i][j + 1][0], dp[i][j][k] + a[i][j + 1]);
                if (i + 1 <= n && k + 1 < 3) dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + a[i + 1][j]);

            }
        }
    }
    int ans = -INF;
    for (int i = 0; i < 3; ++i) ans = max(ans, dp[n][m][i]);
    cout << ans;
    return 0;
}
