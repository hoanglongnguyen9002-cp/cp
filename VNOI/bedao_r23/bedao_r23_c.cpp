// https://oj.vnoi.info/problem/bedao_r23_c#submit
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, deg, a[N], b[N], c[N], d[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> deg;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) cin >> d[i];

    sort(a + 1, a + 1 + n, greater<int>());
    sort(b + 1, b + 1 + n, greater<int>());
    sort(c + 1, c + 1 + n, greater<int>());
    sort(d + 1, d + 1 + n, greater<int>());

    vector<tuple<int,int,int>> x, y;

    priority_queue<tuple<int,int,int>> pq1;
    for (int i = 1; i <= n; ++i) {
        pq1.push({a[1] + b[i], 1, i});
    }
    for (int i = 1; i <= min(deg, n * n); ++i) {
        tuple<int,int,int> tmp = pq1.top();
        pq1.pop();
        x.push_back(tmp);
        int idx_i = get<1>(tmp);
        int idx_j = get<2>(tmp);
        if (idx_i + 1 <= n) {
            pq1.push({a[idx_i + 1] + b[idx_j], idx_i + 1, idx_j});
        }
    }
    
    priority_queue<tuple<int,int,int>> pq2;
    for (int i = 1; i <= n; ++i) {
        pq2.push({c[1] + d[i], 1, i});
    }
    for (int i = 1; i <= min(deg, n * n); ++i) {
        tuple<int,int,int> tmp = pq2.top();
        pq2.pop();
        y.push_back(tmp);
        int idx_i = get<1>(tmp);
        int idx_j = get<2>(tmp);
        if (idx_i + 1 <= n) {
            pq2.push({c[idx_i + 1] + d[idx_j], idx_i + 1, idx_j});
        }
    }
    
    pair<int,int> ans;
    priority_queue<tuple<int,int,int>> pq;
    for (int i = 0; i < (int)y.size(); ++i) {
        int sum = get<0>(x[0]) + get<0>(y[i]);
        pq.push({sum, 0, i});
    }
    while(deg--) {
        tuple<int,int,int> tmp = pq.top();
        pq.pop();
        int i = get<1>(tmp);
        int j = get<2>(tmp);
        ans = {i, j};
        if (i + 1 < (int)x.size()) {
            int sum = get<0>(x[i + 1]) + get<0>(y[j]);
            pq.push({sum, i + 1, j});
        }
    }
    
    
    cout << a[get<1>(x[ans.first])] << ' ' << b[get<2>(x[ans.first])] << 
    ' ' << c[get<1>(y[ans.second])] << ' ' << d[get<2>(y[ans.second])];
    return 0;
}
