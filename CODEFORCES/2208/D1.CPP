#include <bits/stdc++.h>
using namespace std;

const int N = 505;
string s[N], t[N];
vector<pair<int,int>> edges;
vector<int> adj[N], g[N];
bool vs[N];

void dfs(int u, int id) {
    vs[u] = true;
    t[id][u] = '1';
    for (int v : g[u]) {
        if (!vs[v]) dfs(v, id);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            t[i] = string(n, '0');
        }
        edges.clear();
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (u == v) continue;
                if (s[u][v] == '1') {
                    bool check = true;
                    for (int k = 0; k < n; ++k) {
                        if (k == u || k == v) continue;
                        if (s[u][k] == '1' && s[k][v] == '1') {
                            check = false;
                            break;
                        }
                    }
                    if (check) edges.push_back({u, v});
                }
            }
        }

        if ((int)edges.size() != n - 1) {
            cout << "No\n";
            continue;
        }

        // build graph
        for (int i = 0; i < N; ++i) {
            adj[i].clear();
            g[i].clear();
        }
        for (pair<int,int> tmp : edges) {
            int u = tmp.first;
            int v = tmp.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
            g[u].push_back(v);
        }

        // bfs check
        fill(vs, vs + N, false);
        queue<int> q;
        vs[0] = true;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!vs[v]) {
                    vs[v] = true;
                    q.push(v);
                }
            }
        }
        bool check = false;
        for (int i = 0; i < n; ++i) {
            if (!vs[i]) {
                cout << "No\n";
                check = true;
                break;
            }
        }
        if (check) continue;

        // double check
        check = false;
        for (int i = 0; i < n; ++i) {
            fill(vs, vs + N, false);
            dfs(i, i);
            if (t[i] != s[i]) {
                cout << "No\n";
                check = true;
                break;
            }
        }
        if (check) continue;

        // OK
        cout << "Yes\n";
        for (pair<int,int> tmp : edges) cout << tmp.first + 1 << ' ' << tmp.second + 1 << '\n';

    }
    return 0;
}
