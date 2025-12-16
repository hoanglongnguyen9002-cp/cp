#include <bits/stdc++.h>
using namespace std;

const int N = 501 * 2;
int n, m, a[N][N], pref[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * m; ++j) {
            a[i][j] = a[(i % n == 0 ? n : i % n)][(j % m == 0 ? m : j % m)];
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
    int cur_x = 0, cur_y = 0;
    int q;
    cin >> q;
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 0) {
            cur_x += y;
            cur_y += x;
            cur_x %= n;
            cur_y %= m;
        } else {
            int u, v;
            cin >> u >> v;
            x += cur_x;
            y += cur_y;
            u += cur_x;
            v += cur_y;
            cout << pref[u][v] - pref[u][y - 1] - pref[x - 1][v] + pref[x - 1][y - 1] << '\n';
        }
    }
    return 0;
}
