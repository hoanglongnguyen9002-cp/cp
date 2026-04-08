#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long INF = 2e18;
const int N = 100005;

ll dp[N][64];
ll a[N];
int s[10];
int n, m;
ll p, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    freopen("WHOME.INP", "r", stdin);
    freopen("WHOME.OUT", "w", stdout);


    cin >> n >> m >> p >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 0; i <= n; ++i) {
        for (int mask = 0; mask < (1 << m); ++mask) {
            dp[i][mask] = -INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < (1 << m); ++mask) {
            dp[i][mask] = dp[i - 1][mask];
        }
        for (int j = 1; j <= m; ++j) {
            if (i >= s[j]) {
                ll tmp = a[i] - a[i - s[j] + 1];
                ll cost = p - tmp * tmp * c;
                for (int mask = 0; mask < (1 << m); ++mask) {
                    if (dp[i - s[j]][mask] != -INF) {
                        ll nxt = dp[i - s[j]][mask] + cost;
                        int pref = mask | (1 << (j - 1));
                        if (nxt > dp[i][pref]) {
                            dp[i][pref] = nxt;
                        }
                    }
                }
            }
        }
    }

    cout << dp[n][(1 << m) - 1] << '\n';

    return 0;
}
