#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long INF = 1e18;
const int N = 100005;
const int MAX_R = 1000005;

struct Data {
    int l, r, w;
};

Data a[N];
ll tree[MAX_R * 4];
ll lz[MAX_R * 4];
int n;

bool cmp(Data x, Data y) {
    return x.r < y.r;
}

void update(int id, int l, int r, int u, int v, ll val) {
    if (lz[id] != 0) {
        tree[id] = tree[id] + lz[id];
        if (l != r) {
            lz[id * 2] = lz[id * 2] + lz[id];
            lz[id * 2 + 1] = lz[id * 2 + 1] + lz[id];
        }
        lz[id] = 0;
    }
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        tree[id] = tree[id] + val;
        if (l != r) {
            lz[id * 2] = lz[id * 2] + val;
            lz[id * 2 + 1] = lz[id * 2 + 1] + val;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    ll tmp1 = tree[id * 2];
    ll tmp2 = tree[id * 2 + 1];
    if (tmp1 > tmp2) {
        tree[id] = tmp1;
    } else {
        tree[id] = tmp2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    freopen("SSEQ.INP", "r", stdin);
    freopen("SSEQ.OUT", "w", stdout);
    

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }

    sort(a + 1, a + n + 1, cmp);

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        update(1, 1, MAX_R, 1, a[i].l, a[i].w);
        bool check = false;
        if (i == n) {
            check = true;
        } else if (a[i].r != a[i + 1].r) {
            check = true;
        }
        if (check) {
            if (tree[1] > ans) {
                ans = tree[1];
            }
        }
    }

    cout << ans << '\n';
    

    return 0;
}
