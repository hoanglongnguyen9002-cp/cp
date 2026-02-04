#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q, par[N], sz[N], comp;
stack<int> check_point;
stack<pair<int,int>> history;

struct DSU {
    DSU() {
        fill(sz, sz + N, 1);
        iota(par, par + N, 0);
    }

    int Find(int v) {
        return (v == par[v] ? v : par[v] = Find(par[v]));
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a == b) {
            history.emplace(-1, -1);
            return;
        }
        if (sz[a] < sz[b]) swap(a, b);
        comp--;
        sz[a] += sz[b];
        par[b] = a;
        history.emplace(a, b);
    }

    void rollback() {
        pair<int,int> tmp = history.top();
        history.pop();
        int a = tmp.first;
        int b = tmp.second;
        if (a == -1 || b == -1) return;
        comp++;
        sz[a] -= sz[b];
        par[b] = b;
    }
} dsu;

void solve() {
    string type;
    cin >> type;
    if (type == "union") {
        int u, v;
        cin >> u >> v;
        dsu.Union(u, v);
        cout << comp << '\n';
    } else if (type == "persist") {
        check_point.emplace(history.size());
    } else {
        int cur_edges = check_point.top();
        check_point.pop();
        while (history.size() > cur_edges) dsu.rollback();
        cout << comp << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    comp = n;
    while (q--) solve();
    return 0;
}
