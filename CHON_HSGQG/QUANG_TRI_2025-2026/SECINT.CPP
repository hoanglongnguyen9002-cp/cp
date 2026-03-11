// https://codeforces.com/group/6iRxenZ3op/contest/677478/problem/B
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
int n, k, a[N], node[N * 4];
int minL[N], minR[N], id[N];
vector<int> vals;

void upd(int id, int l, int r, int pos, int val) {
    if (l == r) {
        node[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) upd(id * 2, l, mid, pos, val);
    else upd(id * 2 + 1, mid + 1, r, pos, val);
    node[id] = node[id * 2] + node[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return node[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int calc(int l, int r) {
    if (l > r) return 0;
    int res = 0;
    if (l == r) {
        if (a[l] * 3 <= k) res++;
        return res;
    }

    int mid = (l + r) / 2;
    res += calc(l, mid);
    res += calc(mid + 1, r);

    minL[mid] = a[mid];
    for (int i = mid - 1; i >= l; --i) minL[i] = min(minL[i + 1], a[i]);
    minR[mid + 1] = a[mid + 1];
    for (int i = mid + 2; i <= r; ++i) minR[i] = min(minR[i - 1], a[i]);

    vector<int> used;

    int j = mid + 1;
    for (int i = mid; i >= l; --i) {
        while (j <= r && minL[i] < minR[j]) {
            upd(1, 1, vals.size(), id[j], 1);
            used.push_back(j);
            j++;
        }
        int lim = upper_bound(vals.begin(), vals.end(), k - a[i] - minL[i]) - vals.begin();
        res += get(1, 1, vals.size(), 1, lim);
    }
    for (int x : used) upd(1, 1, vals.size(), id[x], -1);
    used.clear();

    int i = mid;
    for (int j = mid + 1; j <= r; ++j) {
        while (l <= i && minR[j] <= minL[i]) {
            upd(1, 1, vals.size(), id[i], 1);
            used.push_back(i);
            i--;
        }
        int lim = upper_bound(vals.begin(), vals.end(), k - a[j] - minR[j]) - vals.begin();
        res += get(1, 1, vals.size(), 1, lim);
    }
    for (int x : used) upd(1, 1, vals.size(), id[x], -1);

    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("SECINT.INP", "r", stdin);
    freopen("SECINT.OUT", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 1; i <= n; ++i) {
        id[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    }

    cout << calc(1, n);


    return 0;
}
