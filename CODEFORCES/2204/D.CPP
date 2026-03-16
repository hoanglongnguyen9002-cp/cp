#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
int n, m;
vector<int> adj[N];
int group[N];
bool check;
ll sum0, sum1;

void dfs(int u) {
    for (int v : adj[u]) {
        if (group[v] == -1) {
            group[v] = 1 - group[u];
            if (group[v] == 0) sum0++;
            else sum1++;
            dfs(v);
        } else if (group[v] == group[u]) check = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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

        fill(group, group + N, -1);
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (group[i] == -1) {
                check = true;
                group[i] = 0;
                sum0 = 1;
                sum1 = 0;
                dfs(i);
                if (check) ans += max(sum0, sum1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
