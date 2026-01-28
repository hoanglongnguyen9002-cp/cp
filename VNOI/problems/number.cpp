// https://oj.vnoi.info/problem/number#submit
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
int n, m, t;
vector<int> adj[N];
bool vs[N], reach[N];
int child[N];
int mx, idx;

void dfs(int u) {
    vs[u] = true;
    child[u] = 1;
    for (int v : adj[u]) {
        if (!reach[v] && !vs[v]) dfs(v);
        if (!reach[v]) child[u] += child[v];
    }
    if (child[u] > mx) {
        mx = child[u];
        idx = u;
    }
}

void dfs_t(int u) {
    reach[u] = true;
    for (int v : adj[u]) if (!reach[v]) dfs_t(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    int ans = 0;
    dfs_t(t);
    while (true) {
        mx = -1;
        fill(vs + 1, vs + 1 + n, false);
        for (int i = 1; i <= n; ++i) {
            if (!vs[i] && !reach[i]) dfs(i);
        }
        if (mx == -1) break;
        adj[t].push_back(idx);
        ans++;
        dfs_t(t);   
    }
    cout << ans;
    return 0;
}