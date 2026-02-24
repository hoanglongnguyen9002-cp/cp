// https://oj.vnoi.info/problem/gl_fear#submit
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
const int N = 301;
int n, m, dist[N][N];
string s, t, x;
vector<pair<int,int>> adj[N];
vector<int> key[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    // for (int i = 1; i < n - 1; ++i) {
    //     adj[i].push_back({i - 1, 1});
    //     adj[i - 1].push_back({i, 1});
    //     adj[i].push_back({i + 1, 1});
    //     adj[i + 1].push_back({i, 1});
    // }


    for (int i = 0; i < n; ++i) {
        if (key[s[i]].empty()) x += s[i];
        key[s[i]].push_back(i);
    }

    for (int i = 0; i < x.size(); ++i) {
        for (int l = 0; l < key[x[i]].size(); ++l) {
            for (int r = l + 1; r < key[x[i]].size(); ++r) {
                adj[key[x[i]][l]].push_back({key[x[i]][r], abs(key[x[i]][l] - key[x[i]][r])});
                adj[key[x[i]][r]].push_back({key[x[i]][l], abs(key[x[i]][l] - key[x[i]][r])});
            }
        }
    }

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < key[t[0]].size(); ++i) {
        pq.push({0, key[t[0]][i], 0});
        dist[key[t[0]][i]][0] = 0;
    }
    while (!pq.empty()) {
        int d = get<0>(pq.top());
        int u = get<1>(pq.top());
        int idx = get<2>(pq.top());
        pq.pop();
        if (d > dist[u][idx]) continue;
        if (idx == m - 1) {
            cout << d;
            return 0;
        }
        if (u + 1 < n && idx < m - 1&& s[u + 1] == t[idx + 1] && dist[u + 1][idx + 1] > dist[u][idx] + 1) {
            pq.push({d + 1, u + 1, idx + 1});
            dist[u + 1][idx + 1] = d + 1;
        }
        if (u - 1 >= 0 && idx < m - 1 && s[u - 1] == t[idx + 1] && dist[u - 1][idx + 1] > dist[u][idx] + 1) {
            pq.push({d + 1, u - 1, idx + 1});
            dist[u - 1][idx + 1] = d + 1;
        }
        for (pair<int,int> tmp : adj[u]) {
            int v = tmp.first;
            int w = tmp.second;
            if (dist[v][idx] > d + w) {
                pq.push({d + w, v, idx});
                dist[v][idx] = d + w;
            }
        }
    }
    cout << -1;
    return 0;
}
