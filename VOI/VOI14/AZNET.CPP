#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
int n, m, a[N], b[N];
struct Edges {
    int u, v, idx;
};
vector<Edges> edgeA, edgeB;
int sz[N], par[N];

struct DSU {
    void reset() {
        fill(sz, sz + N, 1);
        iota(par, par + N, 0);
    }

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
};

void solve() {
    edgeA.clear();
    edgeB.clear();
    cin >> n >> m;
    for (int i = 1; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cin >> b[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        if (c == 1) edgeA.push_back({u, v, i});
        else edgeB.push_back({u, v, i});
    }
    DSU dsu;
    dsu.reset();
    vector<Edges> minA;
    for (Edges e : edgeB) dsu.Union(e.u, e.v);
    for (Edges e : edgeA) if (dsu.Union(e.u, e.v)) minA.push_back(e);
    dsu.reset();
    int maxA = 0;
    for (Edges e : edgeA) if (dsu.Union(e.u, e.v)) maxA++;

    int best = minA.size();
    for (int i = minA.size() + 1; i <= maxA; ++i) {
        if (a[i] + b[(n - 1) - i] < a[best] + b[(n - 1) - best]) best = i;
    }

    vector<int> ans;
    dsu.reset();
    for (Edges e : minA) {
        dsu.Union(e.u, e.v);
        ans.push_back(e.idx);
        best--;
    }
    for (Edges e : edgeA) {
        if (best == 0) break;
        if (dsu.Union(e.u, e.v)) {
            ans.push_back(e.idx);
            best--;
        }
    }
    for (Edges e : edgeB) if (dsu.Union(e.u, e.v)) ans.push_back(e.idx);
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
