#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 1e5 + 5;
int n, m, q;
ll s[N], c[N], dist[N];
vector<pair<int,int>> adj[N];
vector<int> vals;
ll node[N * 4];
struct Query {
    ll l, r, d, id;
    bool operator < (const Query &other) const {
        return d < other.d;
    }

} query[N];
int idx[N];
ll ans[N];

void dijkstra() {
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    fill(dist, dist + N, INF);
    dist[1] = 0;
    pq.push({dist[1], 1});
    while(!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (pair<int,int> e : adj[u]) {
            ll v = e.first;
            ll w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int getID(ll x) {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
}

void upd(int id, int l, int r, int pos, ll value) {
    if (l == r) {
        node[id] = min(node[id], value);
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) upd(id << 1, l, mid, pos, value);
    else upd(id << 1 | 1, mid + 1, r, pos, value);
    node[id] = min(node[id << 1], node[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return INF;
    if (u <= l && r <= v) return node[id];
    int mid = l + r >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("XGRAPH.INP", "r", stdin);
    freopen("XGRAPH.OUT", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cin >> s[i] >> c[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 0; i < q; ++i) {
        cin >> query[i].l >> query[i].r >> query[i].d;
        query[i].id = i;
    }
    sort(query, query + q);

    dijkstra();

    for (int i = 1; i <= n; ++i) vals.push_back(s[i]);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int sz = vals.size();
    fill(node, node + N * 4, INF);

    iota(idx + 1, idx + 1 + n, 1);
    sort(idx + 1, idx + 1 + n, [](const int &x, const int &y){
        return dist[x] < dist[y];
    });
    int pos = 1;
    for (int i = 0; i < q; ++i) {
        ll l = query[i].l;
        ll r = query[i].r;
        ll d = query[i].d;
        while (pos <= n && dist[idx[pos]] <= d) {
            int j = idx[pos];
            upd(1, 1, sz, getID(s[j]), c[j]);
            pos++;
        }
        int L = lower_bound(vals.begin(), vals.end(), l) - vals.begin() + 1;
        int R = upper_bound(vals.begin(), vals.end(), r) - vals.begin();
        ans[query[i].id] = get(1, 1, sz, L, R);
    }
    for (int i = 0; i < q; ++i) cout << (ans[i] == INF ? -1 : ans[i]) << '\n';
    return 0;
}
