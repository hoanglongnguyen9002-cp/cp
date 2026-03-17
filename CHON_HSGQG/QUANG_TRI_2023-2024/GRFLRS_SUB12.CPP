#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int md = 1e9 + 7;
const int N = 4e3 + 3;

int n, m, q, k;
int water[N][N], fert[N][N], h[N][N];
ll dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("GRFLRS.INP", "r", stdin);
    freopen("GRFLRS.OUT", "w", stdout);
    cin >> n >> m >> q >> k;
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        water[x][y] = true;
    }
    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        fert[x][y] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (water[i][j]) water[i][j + 1] = water[i + 1][j] = true;
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
            if (fert[i][j]) fert[i - 1][j] = fert[i][j - 1] = true;
        }
    }

//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cout << water[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            cout << fert[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (water[i][j] && fert[i][j]) h[i][j] = h[i - 1][j] + 1;
            else h[i][j] = 0;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        stack<int> st;
        for (int j = 1; j <= m; ++j) {
            while (!st.empty() && h[i][st.top()] >= h[i][j]) st.pop();
            int k = (st.empty() ? 0 : st.top());
            (dp[j] = dp[k] + h[i][j] * (j - k)) %= md;
            (ans += dp[j]) %= md;
            st.push(j);
        }
    }
    cout << ans << '\n';

    return 0;
}
