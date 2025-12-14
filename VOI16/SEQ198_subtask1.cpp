#include <bits/stdc++.h>
using namespace std;

const int N = 2001;
int m, b[N], a[N];
int ans = INT_MAX;
bool choose[N];

bool check() {
    int n = 0;
    for (int i = 1; i <= m; ++i) {
        if (choose[i]) a[++n] = b[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int val = abs(a[i] - a[j]);
            if (val == 1 || val == 8 || val == 9) return false;
        }
    }
    return true;
}

void backtrack(int id, int cnt = 0) {
    if (id > m) {
        if (check()) ans = min(ans, cnt);
        return;
    }
    backtrack(id + 1, cnt + 1);
    choose[id] = true;
    backtrack(id + 1, cnt);
    choose[id] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    backtrack(1);
    cout << ans;
    return 0;
}

