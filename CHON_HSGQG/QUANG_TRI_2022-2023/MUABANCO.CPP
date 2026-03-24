#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 2e5 + 5;
int n, k, a[N];
ll dp[N][2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("MUABANCO.INP", "r", stdin);
    freopen("MUABANCO.OUT", "w", stdout);
    cin >> n >> k;  
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) dp[i][1] = -INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = k; j >= 1; --j) {
            dp[j][0] = max(dp[j][0], dp[j][1] + a[i]);
            dp[j][1] = max(dp[j][1], dp[j - 1][0] - a[i]);
        }
    }
    cout << dp[k][0] << '\n';
    return 0;
}
