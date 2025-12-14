#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int a[N][N], pref_row[N][N], pref_col[N][N], dp[N][N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pref_row[i][j] = pref_row[i][j - 1] + a[i][j];
            pref_col[i][j] = pref_col[i - 1][j] + a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = 0;
            if (pref_row[i][j] % 2 == 0) dp[i][j] = max(dp[i][j], 1 - dp[i - 1][j]);
            if (pref_col[i][j] % 2 == 0) dp[i][j] = max(dp[i][j], 1 - dp[i][j - 1]);
        }
    }
    cout << (dp[n][n] ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    while (k--) solve();
    return 0;
}
