#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, state_light[N], par[N], cnt[N], deg_in[N], cnt_in[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SOFTWARE.INP", "r", stdin);
    freopen("SOFTWARE.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> state_light[i];
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        par[a] = b;
        deg_in[b]++;
    }
    vector<int> leaf;
    for (int i = 1; i <= n; ++i) if (deg_in[i] == 0) leaf.push_back(i);

    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        cnt[par[x]]++;
    }
    queue<int> q;
    for (int u : leaf) q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 1) break;
        state_light[u] ^= (cnt[u] % 2);
        int v = par[u];
        cnt_in[v]++;
        cnt[v] += cnt[u];
        if (cnt_in[v] == deg_in[v]) q.push(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += state_light[i];
    cout << ans;
    return 0;
}
/*
5 3
1 0 0 0 0
2 1
4 2
3 2
5 4
4 5 4
*/
