// https://oj.vnoi.info/problem/bedao_r23_d#submit
#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e5 + 5;
int n, a[N], b[N], c[N], pref[N], node[N * 4 * 2];

void upd(int id, int l, int r, int pos) {
    if (l == r) {
        node[id]++;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) upd(id * 2, l, mid, pos);
    else upd(id * 2 + 1, mid + 1, r, pos);
    node[id] = node[id * 2] + node[id * 2 + 1];
}

int get(int id, int l, int r, int x) {
    if (x < l) return 0;
    if (r <= x) return node[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, x) + get(id * 2 + 1, mid + 1, r, x);
}

int calc(int x) {
    for (int i = 1; i <= n; ++i) {
        c[i] = (a[i] >= x ? 1 : -1);
    }

    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + c[i];
    }

    fill(node, node + 2 * 4 * N, 0);
    int res = 0;
    int neg = n + 1;
    upd(1, 1, 2 * n, 0 + neg);
    for (int i = 1; i <= n; ++i) {
        res += get(1, 1, 2 * n, pref[i] - 1 + neg);
        upd(1, 1, 2 * n, pref[i] + neg);
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int m = b[(n + 1) / 2];
    
    cout << calc(m) - calc(m + 1);
    return 0;
}
