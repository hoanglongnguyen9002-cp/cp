#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
int n, a[N];

bool check(int x) {
    int n = (sqrt(1 + 8 * x) - 1) / 2;
    if (n * (n + 1) / 2 == x) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] > a[i]) cnt = 0;
        if (check(a[i])) {
            cnt++;
            ans = max(ans, cnt);
        } else cnt = 0;
    }
    cout << ans;
    return 0;
}

