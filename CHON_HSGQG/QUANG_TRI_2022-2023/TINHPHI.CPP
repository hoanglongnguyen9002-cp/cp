#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 1e5 + 5;
int n, m, k, s, t;
vector<pair<int,int>> adj[N];
ll dist[N][15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TINHPHI.INP", "r", stdin);
    freopen("TINHPHI.OUT", "w", stdout);
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 15; ++j) {
            dist[i][j] = INF;
        }
    }
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
    for (int i = 0; i <= k; ++i) {
        dist[s][i] = 0;
        pq.push({dist[s][i], s, i});
    }
    while (!pq.empty()) {
        ll d = get<0>(pq.top());
        int u = get<1>(pq.top());
        int done = get<2>(pq.top());
        pq.pop();
        if (d > dist[u][done]) continue;
        for (pair<int,int> e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            if (dist[v][done] > dist[u][done] + w) {
                dist[v][done] = dist[u][done] + w;
                pq.push({dist[v][done], v, done});
            }
            if (done + 1 <= k && dist[v][done + 1] > dist[u][done]) {
                dist[v][done + 1] = dist[u][done];
                pq.push({dist[v][done + 1], v, done + 1});
            }
        }

    }
    ll ans = INF;
    for (int i = 0; i <= k; ++i) ans = min(ans, dist[t][i]);
    cout << ans;
    return 0;
}
