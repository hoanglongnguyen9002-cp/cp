// https://oj.vnoi.info/problem/olp304_16_taitrong
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
int n, m, s, t;
vector<pair<int,int>> adj[N];
bool vs[N];

bool check(int x) {
    fill(vs, vs + N, false);
    queue<int> q;
    q.push(s);
    vs[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t) return true;
        for (pair<int,int> tmp : adj[u]) {
            int v = tmp.first;
            int w = tmp.second;
            if (!vs[v] && w >= x) {
                vs[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("TAITRONG.INP", "r", stdin);
    freopen("TAITRONG.OUT", "w", stdout);

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int l = 1, r = 1e4, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans;
    return 0;
}
