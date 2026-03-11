#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
const int base = 31;
const int md = 1e9 + 7;
const int N = 5e4 + 4;
const int M = 55;

int n, m, K;
string s;
string key[M];
bool bad[M][M];
//ll dp[5000][5000];
//map<string,bool> mp;
ll dp_pref[N][M], dp_suff[N][M];
ll p[N], hashS[N], Hash[M];


ll add(ll a, ll b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

ll mul(ll a, ll b) {
    return (a * b) % md;
}

ll get(int l, int r) {
    return (hashS[r] - hashS[l - 1] * p[r - l + 1] + 1ll * md * md) % md;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    freopen("ABLANG.INP", "r", stdin);
//    freopen("ABLANG.OUT", "w", stdout);

    cin >> n >> m >> K >> s;
    s = ' ' + s;
    for (int i = 1; i <= m; ++i) cin >> key[i];
    for (int i = 1; i <= K; ++i) {
        int x, y;
        cin >> x >> y;
        bad[x][y] = true;
    }

    // HASH
    p[0] = 1;
    for (int i = 1; i < N; ++i) p[i] = mul(p[i - 1], base);
    for (int i = 1; i <= n; ++i) hashS[i] = (hashS[i - 1] * base + (s[i] - 'a' + 1)) % md;
    for (int id = 1; id <= m; ++id) {
        for (int i = 1; i <= key[id].size(); ++i) {
            Hash[id] = (Hash[id] * base + (key[id][i - 1] - 'a' + 1)) % md;
        }
    }

    // DP
    dp_pref[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int len = key[j].size();
            if (i >= len) {
                if (get(i - len + 1, i) == Hash[j]) {
                    for (int k = 0; k <= m; ++k) {
                        if (bad[k][j]) continue;
                        dp_pref[i][j] = add(dp_pref[i][j], dp_pref[i - len][k]);
                    }
                }
            }
        }
    }

    dp_suff[n + 1][0] = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            int len = key[j].size();
            if (i + len - 1 <= n) {
                if (get(i, i + len -1) == Hash[j]) {
                    for (int k = 0; k <= m; ++k) {
                        if (bad[j][k]) continue;
                        dp_suff[i][j] = add(dp_suff[i][j], dp_suff[i + len][k]);
                    }
                }
            }
        }
    }

    for (int id = 1; id <= m; ++id) {
        ll ans = 0;
        int len = key[id].size();
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (get(i, j) == Hash[id]) {
                ll pref = 0;
                for (int k = 0; k <= m; ++k) {
                    if (bad[k][id]) continue;
                    pref = add(pref, dp_pref[i - 1][k]);
                }
                ll suff = 0;
                for (int k = 0; k <= m; ++k) {
                    if (bad[id][k]) continue;
                    suff = add(suff, dp_suff[j + 1][k]);
                }
                ans = add(ans, mul(pref, suff));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
