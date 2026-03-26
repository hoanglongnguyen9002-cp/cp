#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int LOG = 18;
const int MOD = 1 << 20;

int n, m;
int h[N], p[N][LOG], d[N], d_val[N];
int u_edge[N], v_edge[N];

int head_t[N], nxt_t[N * 2], to_t[N * 2], e_idx;
int head_q[N], nxt_q[N * 2], to_q[N * 2], w_q[N * 2], lca_q[N * 2], q_idx;

int q[N];
int bit_val[N];

void add_tree(int u, int v) {
    to_t[++e_idx] = v;
    nxt_t[e_idx] = head_t[u];
    head_t[u] = e_idx;
}

void add_query(int u, int v, int w, int lca) {
    to_q[++q_idx] = v;
    w_q[q_idx] = w;
    lca_q[q_idx] = lca;
    nxt_q[q_idx] = head_q[u];
    head_q[u] = q_idx;
}

void dfs(int u, int pa) {
    h[u] = h[pa] + 1;
    p[u][0] = pa;
    for (int i = 1; i < LOG; ++i) {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (int i = head_t[u]; i; i = nxt_t[i]) {
        int v = to_t[i];
        if (v != pa) dfs(v, u);
    }
}

int get_lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; --i) {
        if (h[p[u][i]] >= h[v]) u = p[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

bool solve(int bit) {
    fill(bit_val + 1, bit_val + n + 1, -1);
    ll cur_mod = 1LL << (bit + 1);

    for (int i = 1; i <= n; ++i) {
        if (bit_val[i] != -1) continue;
        bit_val[i] = 0;
        int head = 0, tail = 0;
        q[++tail] = i;

        while (head < tail) {
            int u = q[++head];
            for (int j = head_q[u]; j; j = nxt_q[j]) {
                int v = to_q[j];
                ll path_sum = (ll)w_q[j] - d_val[u] - d_val[v] + 2LL * d_val[lca_q[j]];
                path_sum %= cur_mod;
                if (path_sum < 0) path_sum += cur_mod;

                int req_xor = (path_sum >> bit) & 1;
                int exp_val = bit_val[u] ^ req_xor;

                if (bit_val[v] == -1) {
                    bit_val[v] = exp_val;
                    q[++tail] = v;
                } else if (bit_val[v] != exp_val) return false;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        d_val[i] += (1 << bit) * bit_val[i];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("STREE.INP", "r", stdin);
    freopen("STREE.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u_edge[i] >> v_edge[i];
        add_tree(u_edge[i], v_edge[i]);
        add_tree(v_edge[i], u_edge[i]);
    }

    dfs(1, 0);

    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        int lca = get_lca(u, v);
        add_query(u, v, w, lca);
        add_query(v, u, w, lca);
    }

    for (int i = 0; i < 20; ++i) {
        if (!solve(i)) {
            cout << "INDETERMINATE\n";
            return 0;
        }
    }

    cout << "UNIQUE\n";
    for (int i = 1; i < n; ++i) {
        int u = u_edge[i], v = v_edge[i];
        if (h[u] > h[v]) swap(u, v);
        int res = (d_val[v] - d_val[u]) % MOD;
        if (res < 0) res += MOD;
        cout << res << ' ';
    }

    return 0;
}
