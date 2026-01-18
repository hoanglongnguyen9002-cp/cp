// https://codeforces.com/contest/2191/problem/B
#include <bits/stdc++.h>
using namespace  std;

void solve() {
    int n;
    cin >> n;
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) cnt++;
        if (x == 1) cnt1++;
    }
    if (cnt == 1 || (cnt && cnt1)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}