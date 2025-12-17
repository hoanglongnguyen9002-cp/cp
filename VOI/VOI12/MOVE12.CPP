#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
const int INF = INT_MAX;
int n, c[N], t[N];

bool check(int x) {
    vector<pair<int,int>> seg;
    for (int i = 1; i <= n; ++i) {
        int l = max(1, c[i] - x / t[i]);
        int r = min(n, c[i] + x / t[i]);
        seg.emplace_back(l, r);
    }
    sort(seg.begin(), seg.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        while (idx < n && seg[idx].first <= i) pq.push(seg[idx++].second);
        if (pq.empty() || pq.top() < i) return false;
        pq.pop();
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i] >> t[i];
    int l = 0, r = INF;
    int ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;
    return 0;
}

