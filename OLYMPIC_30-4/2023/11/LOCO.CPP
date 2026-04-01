#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 1e5 + 5;
int n, p;
ll a[5][N], dp[5][N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("LOCO.INP", "r", stdin);
    freopen("LOCO.OUT", "w", stdout);
    cin >> n >> p;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = -INF;
        }
    }
    dp[1][0] = dp[2][0] = dp[3][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= i + p; ++j) {
            dp[1][j] = max(dp[1][j], dp[2][i] + a[1][j]);
            dp[2][j] = max({dp[2][j], dp[1][i] + a[2][j], dp[3][i] + a[2][j]});
            dp[3][j] = max(dp[3][j], dp[2][i] + a[3][j]);
        }
    }
    cout << max({dp[1][n + 1], dp[2][n + 1], dp[3][n + 1]});
    return 0;
}
/*
6 3
3 -4 -5 5 10 2
6 2 -3 -2 1 -1
-2 13 1 0 7 4
*/
