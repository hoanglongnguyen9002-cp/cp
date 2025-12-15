#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 501;
int n, m;
bool power[N];
struct Edges {
    int v, t, c;
};
vector<Edges> adj[N];
int dist[N];
vector<pair<int,int>> par[N];

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    fill(dist, dist + N, INF);
    pq.emplace(0, 1);
    dist[1] = 0;
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (Edges tmp : adj[u]) {
            int v = tmp.v;
            int t = tmp.t;
            int c = tmp.c;
            if (dist[v] > dist[u] + t) {
                dist[v] = dist[u] + t;
                par[v].clear();
                par[v].emplace_back(u, c);
                pq.emplace(dist[v], v);
            } else if (dist[v] == dist[u] + t) {
                par[v].emplace_back(u, c);
            }
        }
    }
}

bool check(int W) {
    queue<pair<int,int>> q;
    q.emplace(n, W);
    while (!q.empty()) {
        int v = q.front().first;
        int w = q.front().second;
        q.pop();
        if (v == 1) return true;
        for (pair<int,int> tmp : par[v]) {
            int u = tmp.first;
            int c = tmp.second;
            if (c > w) continue;
            q.emplace(u, (power[u] ? W : w - c));

        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> power[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        adj[u].push_back({v, t, c});
        adj[v].push_back({u, t, c});
    }
    dijkstra();
    int l = 0, r = 1e9;
    int ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    cout << ans;
    return 0;
}
