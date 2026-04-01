#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, s, k, a[N];
vector<pair<int,int>> adj[N], g[N];
bool done[N];
ll cur_point;
bool vs[N];

//struct Edges {
//    int u, v, w;
//    bool operator < (const Edges &other) const {
//        return w < other.w;
//    }
//};
//int sz[N], par[N];
//
//int Find(int v) {
//    if (v == par[v] ? v : par[v] = Find(par[v]));
//}
//
//void Union(Edges e) {
//    int a = Find(e.u);
//    int b = Find(e.v);
//    if (a == b) return;
//    if (sz[a] < sz[b]) swap(a, b);
//    sz[a] += sz[b];
//    par[b] = a;
//    g[e.u].emplace_back(e.v, e.w);
//    g[e.v].emplace_back(e.u, e.w);
//}

int calc(int st) {
    int res = 1;
    queue<int> q;
    vs[st] = true;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (pair<int,int> e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (!vs[v] && w <= cur_point) {
                vs[v] = true;
                res++;
                q.push(v);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> n >> m >> s >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
//        edges.push_back({u, v, w});
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    done[s] = true;
    for (pair<int,int> e : adj[s]) pq.push({e.second, e.first});
    cur_point = a[s];
    ll ans = 1;
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (done[u]) continue;
        if (cur_point >= d) {
            cur_point += a[u];
            done[u] = true;
            ans++;
            for (pair<int,int> e : adj[u]) {
                if (done[e.first]) continue;
                pq.push({e.second, e.first});
            }
        } else break;
    }

    int cnt = 0;
    if (k == 1) {
//        sort(edges.begin(), edges.end());
//        fill(sz, sz + N, 1);
//        iota(par, par + N, 0);
//        for (Edges e : edges) Union(e);
        copy(done, done + N, vs);
        for (int u = 1; u <= n; ++u) {
            if (done[u]) {
                for (pair<int,int> e : adj[u]) {
                    int v = e.first;
                    if (!vs[v]) cnt = max(cnt, calc(v));
                }
            }
        }
    }
    ans += cnt;
    cout << ans << '\n';
    return 0;
}
