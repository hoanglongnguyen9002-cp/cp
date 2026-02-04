#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
struct Edges {
    int v;
    ll l, c;
};
vector<Edges> adj[200001];

void dijkstra() {
    priority_queue<pair<pair<ll,ll>,int>, vector<pair<pair<ll,ll>,int>>, greater<pair<pair<ll,ll>,int>>> pq;
    vector<pair<ll,ll>> dist(n + 1, {LLONG_MAX, LLONG_MIN});
    dist[1] = {0, 0};
    pq.emplace(dist[1], 1);
    while (!pq.empty()) {
        ll d = pq.top().first.first;
        ll val = pq.top().first.second;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u].first) continue;
        if (u == n) {
            cout << dist[n].first << ' ' << dist[n].second;
            return;
        }
        for (Edges tmp : adj[u]) {
            int v = tmp.v;
            ll l = tmp.l;
            ll c = tmp.c;
            if (dist[v].first > dist[u].first + l) {
                dist[v].first = dist[u].first + l;
                dist[v].second = dist[u].second + c;
                pq.emplace(dist[v], v);
            } else if (dist[v].first == dist[u].first + l) {
                if (dist[v].second < dist[u].second + c) {
                    dist[v].second = dist[u].second + c;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        adj[u].push_back({v, l, c});
        adj[v].push_back({u, l, c});
    }
    dijkstra();
    return 0;
}