#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
int k;
bool c[20][20];
string s;
ll nx[105][20], dp[1 << 20][105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("KSTRING.INP", "r", stdin);
    freopen("KSTRING.OUT", "w", stdout);
    cin >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> c[i][j];
        }
    }
    cin >> s;
    int n = s.size();
    fill(nx[n], nx[n] + k, INF);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '*') {
            for (int j = 0; j < k; ++j) nx[i][j] = nx[i + 1][j];
            nx[i][(s[i] - 'a')] = i;
        } else fill(nx[i], nx[i] + k, i);
    }
    ll MASK = (1 << k) - 1;
    dp[0][0] = 1;
    for (int mask = 0; mask <= MASK; ++mask) {
        int done = __builtin_popcount(mask);
        for (int i = 0; i <= n; ++i) {
            if (!dp[mask][i]) continue;
            for (int j = 0; j < k; ++j) {
                if ((mask & (1 << j)) || !c[j][done]) continue;
                if (nx[i][j] == INF) continue;
                dp[mask | (1 << j)][nx[i][j] + 1] += dp[mask][i];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) ans += dp[MASK][i];
    cout << ans;
    return 0;
}
