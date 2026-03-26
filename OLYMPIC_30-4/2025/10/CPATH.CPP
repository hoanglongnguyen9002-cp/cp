#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 1e9;
int n, m;
vector<int> pos[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CPATH.INP", "r", stdin);
    freopen("CPATH.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        pos[c].push_back(i);
    }
    int ans = INF;
    for (int c = 1; c <= m; ++c) {
        int mx1 = 0, mx2 = 0, mx = 0, pre = 0;
        for (int i = 1; i < (int)pos[c].size() - 1; ++i) mx1 = max(mx1, pos[c][i + 1] - pos[c][i]);
        for (int i = (int)pos[c].size() - 2; i > 0; --i) mx2 = max(mx2, pos[c][i] - pos[c][i - 1]);
        for (int i = 0; i < (int)pos[c].size() - 1; ++i) {
            int dist = pos[c][i + 1] - pos[c][i];
            if (mx < dist) {
                pre = mx;
                mx = dist;
            } else if (pre < dist) pre = dist;
        }
        ans = min({ans, mx1, mx2, max(pre, (mx + 1) / 2)});
    }
    cout << ans;
    return 0;
}
