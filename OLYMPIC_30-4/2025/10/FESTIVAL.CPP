#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1e18;
const int N = 1e6 + 6;
int n, nx[N], rk[N];
ll h[N], s[N];
struct Ban {
    ll id_pre, id_ban, step, cur_h;
    static Ban compare(const Ban &x, const Ban &y) {
        if (x.step < y.step) return x;
        else if (x.step > y.step) return y;
        if (x.step == y.step) {
            if (x.cur_h > y.cur_h) return y;
            else if (x.cur_h < y.cur_h) return x;
            if (x.cur_h == y.cur_h) {
                if (s[x.id_ban] > s[y.id_ban]) return y;
                else if (s[x.id_ban] < s[y.id_ban]) return x;
            }
        }
        return x;
    }

    static bool similar(const Ban &x, const Ban &y) {
        if (x.step < y.step) return false;
        else if (x.step > y.step) return false;
        if (x.step == y.step) {
            if (x.cur_h > y.cur_h) return false;
            else if (x.cur_h < y.cur_h) return false;
            if (x.cur_h == y.cur_h) {
                if (s[x.id_ban] > s[y.id_ban]) return false;
                else if (s[x.id_ban] < s[y.id_ban]) return false;
                return true;
            }
        }
        return true;
    }
} ban[N];

struct CmpBan {
    bool operator()(const Ban &a, const Ban &b) const {
        if (a.step != b.step) return a.step > b.step;
        if (a.cur_h != b.cur_h) return a.cur_h > b.cur_h;
        if (s[a.id_ban] != s[b.id_ban]) return s[a.id_ban] > s[b.id_ban];
        return a.id_pre > b.id_pre;
    }
};
ll last_update[N];
bool die[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("FESTIVAL.INP", "r", stdin);
    freopen("FESTIVAL.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i < n; ++i) nx[i] = i + 1;
    nx[n] = 1;

    priority_queue<Ban, vector<Ban>, CmpBan> pq;
    for (int i = 1; i <= n; ++i) {
        int j = nx[i];
        ll cnt = (h[j] <= 0 ? 0 : (h[j] + s[i] - 1) / s[i]);
        ll cur = h[j] - cnt * s[i];
        pq.push({i, j, cnt, cur});
    }

    ll cnt_step = 0;
    for (int idx = 1; idx <= n; ++idx) {
        Ban x = {-1, -1, INF, INF};
        while (!pq.empty()) {
            x = pq.top();
            pq.pop();
            if (die[x.id_ban] || die[x.id_pre] || nx[x.id_pre] != x.id_ban) continue;
            break;
        }

        cnt_step = x.step;
        ban[idx] = x;
        die[x.id_ban] = true;
        int prev = x.id_pre;
        int next = nx[x.id_ban];
        if (next != -1 && !die[next]) {
            ll tmp = cnt_step - last_update[next];
            if (tmp > 0) {
                h[next] -= tmp * s[x.id_ban];
                last_update[next] = cnt_step;
            }
            ll cnt = (h[next] <= 0 ? 0 : (h[next] + s[prev] - 1) / s[prev]);
            ll cur = h[next] - cnt * s[prev];
            pq.push({prev, next, cnt_step + cnt, cur});
        }
        nx[x.id_pre] = nx[x.id_ban];
        nx[x.id_ban] = -1;
    }
    reverse(ban + 1, ban + 1 + n);
    Ban pre = ban[1];
    rk[ban[1].id_ban] = 1;
    for (int i = 2; i <= n; ++i) {
        if (Ban::similar(ban[i], pre)) rk[ban[i].id_ban] = rk[ban[i - 1].id_ban];
        else rk[ban[i].id_ban] = i;
        pre = ban[i];
    }
    for (int i = 1; i <= n; ++i) cout << rk[i] << ' ';
    return 0;
}
