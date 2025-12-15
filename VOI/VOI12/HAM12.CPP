#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int n, m, k;
string a, b[101];

int haming(string x, string y) {
    int res = 0;
    for (int i = 0; i < m; ++i) if (x[i] != y[i]) res++;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> a;
    for (int i = 1; i <= k; ++i) cin >> b[i];
    a += a;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        string t = a.substr(i, m);
        for (int j = 1; j <= k; ++j) {
            ans = min(ans, haming(t, b[j]));
        }
    }
    cout << ans;
    return 0;
}
