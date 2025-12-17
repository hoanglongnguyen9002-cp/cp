#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, k;
bool bad[N][N];
int dx1[3] = {0, 1, 1};
int dy1[3] = {1, 0, 1};
int dx2[3] = {0, 1, 1};
int dy2[3] = {-1,0,-1};
pair<int,int> q1[10000000], q2[10000000];
int s1, f1, s2, f2, times;
bool cur1[N][N], cur2[N][N], ok;

bool insize(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

void bfs1() {
    int idx = f1;
    for (int i = s1; i <= f1; ++i) {
        int x = q1[i].first;
        int y = q1[i].second;
        for (int d = 0; d < 3; ++d) {
            int nx = dx1[d] + x;
            int ny = dy1[d] + y;
            if (!insize(nx, ny) || bad[nx][ny]) continue;
            if (cur1[nx][ny]) continue;
            cur1[nx][ny] = true;
            q1[++idx] = {nx, ny};
        }
    }
    s1 = f1 + 1;
    f1 = idx;
}

void bfs2() {
    int idx = f2;
    for (int i = s2; i <= f2; ++i) {
        int x = q2[i].first;
        int y = q2[i].second;
        for (int d = 0; d < 3; ++d) {
            int nx = dx2[d] + x;
            int ny = dy2[d] + y;
            if (!insize(nx, ny) || bad[nx][ny]) continue;
            if (cur1[nx][ny]) {
                ok = true;
                cout << times;
                return;
            }
            if (cur2[nx][ny]) continue;
            cur2[nx][ny] = true;
            q2[++idx] = {nx, ny};
        }
    }
    s2 = f2 + 1;
    f2 = idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int u, v;
        cin >> u >> v;
        bad[u][v] = true;
    }
    q1[1] = {1, 1};
    q2[1] = {1, n};
    s1 = 1, f1 = 1;
    s2 = 1, f2 = 1;
    cur1[1][1] = true;
    cur2[1][n] = true;
    while (true) {
        times++;
        bfs1();
        bfs2();
        if (ok) return 0;
        for (int i = s1; i <= f1; ++i) cur1[q1[i].first][q1[i].second] = false;
        for (int i = s2; i <= f2; ++i) cur2[q2[i].first][q2[i].second] = false;
    }
    return 0;
}
