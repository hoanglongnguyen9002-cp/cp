#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int LOG = 20;
int n, q, a[N];
string s;
ll pref[N];
int pos[N];
pair<ll,int> tmp[N];
int p[N][LOG + 5], pts[N][LOG + 5];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("QSNAIL.INP", "r", stdin);
    freopen("QSNAIL.OUT", "w", stdout);
    cin >> n >> q >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    int m = 0;
    for (int i = 0; i < n; ++i) if (s[i] == '1') pos[++m] = i + 1;
    pos[0] = 0;
    pos[m + 1] = n + 1;
    for (int i = 0; i <= n; ++i) tmp[i] = {pref[i], i};
    for (int k = 0; k <= m; ++k) sort(tmp + pos[k], tmp + pos[k + 1]);
    for (int k = 0; k < m; ++k) {
        for (int x = pos[k]; x < pos[k + 1]; ++x) {
            ll val = pref[x];
            pair<ll,int> target = {val, -1};
            pair<ll,int>* it = lower_bound(tmp + pos[k + 1], tmp + pos[k + 2], target);
            if (it != tmp + pos[k + 2]) {
                p[x][0] = it->second;
                pts[x][0] = 1;
            } else {
                p[x][0] = tmp[pos[k + 1]].second;
                pts[x][0] = 0;
            }
        }
    }
    for (int x = pos[m]; x <= n; ++x) {
        p[x][0] = n + 1;
        pts[x][0] = 0;
    }
    p[n + 1][0] = n + 1;
    pts[n + 1][0] = 0;
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i <= n + 1; ++i) {
            int nxt = p[i][j - 1];
            p[i][j] = p[nxt][j - 1];
            pts[i][j] = pts[i][j - 1] + pts[nxt][j - 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int a_idx = lower_bound(pos + 1, pos + m + 1, l) - pos;
        int b_idx = upper_bound(pos + 1, pos + m + 1, r) - pos - 1;
        int k = b_idx - a_idx + 1;
        if (k == 1) {
            if (pref[r] >= pref[l - 1]) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            int u = l - 1;
            int steps = k - 1;
            int ans = 0;
            for (int j = 0; j < LOG; ++j) {
                if ((steps >> j) & 1) {
                    ans += pts[u][j];
                    u = p[u][j];
                }
            }
            if (pref[r] >= pref[u]) ans++;
            cout << ans << '\n';
        }
    }
    return 0;
}
