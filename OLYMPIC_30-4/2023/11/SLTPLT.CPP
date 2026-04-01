#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, par[N], sz[N], cnt[N];
vector<int> adj[N];

int Find(int v) {
    return (v == par[v] ? v : par[v] = Find(par[v]));
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SLTPLT.INP", "r", stdin);
    freopen("SLTPLT.OUT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(sz, sz + N, 1);
        iota(par, par + N, 0);
        fill(cnt, cnt + N, 0);
        for (int u = 1; u <= n; ++u) {
            adj[u].push_back(0);
            adj[u].push_back(n + 1);
            sort(adj[u].begin(), adj[u].end());
            for (int i = 0; i < adj[u].size() - 1; ++i) {
                int l = adj[u][i] + 1;
                int r = adj[u][i + 1] - 1;
                if (r < l) continue;
                Union(u, l);
                cnt[l]++;
                cnt[r]--;
            }
        }
        for (int i = 1; i < n; ++i) {
            cnt[i] += cnt[i - 1];
            if (cnt[i]) {
                Union(i, i + 1);
            }
        }
        vector<int> res;
        for (int u = 1; u <= n; ++u) if (u == par[u]) res.push_back(sz[u]);
        cout << res.size() << '\n';
        sort(res.begin(), res.end());
        for (int x : res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
/*
2
4 4
1 3
1 4
2 3
2 4
3 1
1 2
*/
