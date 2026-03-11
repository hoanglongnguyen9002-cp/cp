// https://codeforces.com/group/6iRxenZ3op/contest/677478/problem/B
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int md = 1e9 + 7;
const int N = 5e5 + 5;
int n, q, a[N];

int mul(int a, int b) {
    return (a * b) % md;
}

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

struct Node {
    int ans1, ans2;
    int pref1, pref2;
    int suff1, suff2;
    int len;
    int sum;
} node[N * 4];

Node Merge(Node a, Node b) {
    Node res;
    int x, y, z;

    x = mul(a.len, b.pref1);
    y = mul(a.suff1, b.len);
    int new_ans1 = add(x, y);
    res.ans1 = add(add(a.ans1, b.ans1), new_ans1);

    x = mul(a.suff2, b.len);
    y = mul(a.len, b.pref2);
    z = mul(2, mul(a.suff1, b.pref1));
    int new_ans2 = add(x, add(y, z));
    res.ans2 = add(add(a.ans2, b.ans2), new_ans2);

    res.pref1 = add(a.pref1, add(b.pref1, mul(b.len, a.sum)));
    res.suff1 = add(b.suff1, add(a.suff1, mul(a.len, b.sum)));

    // (a.sum + b.pref)^2
    x = mul(mul(a.sum, a.sum), b.len);
    y = mul(mul(2, a.sum), b.pref1);
    z = b.pref2;
    int new_pref2 = add(x, add(y, z));
    res.pref2 = add(a.pref2, new_pref2);
    // (a.suff + b.sum)^2
    x = mul(mul(b.sum, b.sum), a.len);
    y = mul(mul(2, b.sum), a.suff1);
    z = a.suff2;
    int new_suff2 = add(x, add(y, z));
    res.suff2 = add(b.suff2, new_suff2);

    res.len = a.len + b.len;
    res.sum = add(a.sum, b.sum);
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        node[id].ans1 = a[l];
        node[id].ans2 = mul(a[l], a[l]);
        node[id].pref1 = a[l];
        node[id].pref2 = mul(a[l], a[l]);
        node[id].suff1 = a[l];
        node[id].suff2 = mul(a[l], a[l]);
        node[id].len = 1;
        node[id].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    node[id] = Merge(node[id * 2], node[id * 2 + 1]);
}

void upd(int id, int l, int r, int pos, int val) {
    if (l == r) {
        node[id].ans1 = val;
        node[id].ans2 = mul(val, val);
        node[id].pref1 = val;
        node[id].pref2 = mul(val, val);
        node[id].suff1 = val;
        node[id].suff2 = mul(val, val);
        node[id].len = 1;
        node[id].sum = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) upd(id * 2, l, mid, pos, val);
    else upd(id * 2 + 1, mid + 1, r, pos, val);
    node[id] = Merge(node[id * 2], node[id * 2 + 1]);
}

Node get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return {0, 0, 0, 0, 0, 0, 0, 0};
    if (u <= l && r <= v) return node[id];
    int mid = (l + r) / 2;
    Node x = get(id * 2, l, mid, u, v);
    Node y = get(id * 2 + 1, mid + 1, r, u, v);
    return Merge(x, y);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("KSUM.INP", "r", stdin);
    freopen("KSUM.OUT", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            upd(1, 1, n, x, y);
        } else {
            int k;
            cin >> k;
            Node ans = get(1, 1, n, x, y);
            if (k == 1) cout << ans.ans1 << '\n';
            else cout << ans.ans2 << '\n';
        }
    }


    return 0;
}
