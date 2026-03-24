#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 21);
int n, m, a[N], vs[N], MASK;
bool has[N];

void dfs(int u) {
    vs[u] = true;
    for (int i = 0; i < m; ++i) {
        if ((u >> i) & 1) {
            int v = (u ^ (1 << i));
            if (!vs[v]) dfs(v);
        }
    }
    if (has[u]) {
        int v = MASK ^ u;
        if (!vs[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("COUNT.INP", "r", stdin);
    freopen("COUNT.OUT", "w", stdout);
    cin >> n >> m;
    MASK = (1 << m) - 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        has[a[i]] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vs[a[i]]) {
            ans++;
            int u = MASK ^ a[i];
            if (!vs[u]) {
                dfs(u);
                vs[u] = true;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
