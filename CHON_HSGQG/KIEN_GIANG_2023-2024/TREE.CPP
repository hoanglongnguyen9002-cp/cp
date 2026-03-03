// https://codeforces.com/group/6iRxenZ3op/contest/674259/problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, deg[N], col[N], cop[N];
bool del[N];
vector<int> adj[N];

int bfs(int c) {
    bool check = false;
    for (int i = 1; i <= n; ++i) {
        if (col[i] == c) check = true;
    }
    if (!check) return -1;
    
    
    int cnt = n;
    // for (int i = 1; i <= n; ++i) cout << deg[i] << ' ';cout << endl;
    // copy(deg + 1, deg + 1 + n, cop);
    for (int i = 1; i <= n; ++i) cop[i] = deg[i];
    
    fill(del, del + N, false);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1 && col[i] != c) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        del[u] = true;
        deg[u]--;
        cnt--;
        for (int v : adj[u]) {
            if (!del[v]) {
                deg[v]--;
                if (deg[v] == 1 && col[v] != c) q.push(v);
            }
        }

    }

    for (int i = 1; i <= n; ++i) deg[i] = cop[i];

    return cnt - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
 
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
    }

    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int c;
            cin >> c;
            cout << bfs(c) << '\n';
        } else {
            int x, c;
            cin >> x >> c;
            col[x] = c;
        }
    }

    return 0;
}