#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long INF = 1e18;
const int N = 2005;

struct Score {
    int x, y, z;
    Score() {}
    Score(int s, int p_val, int a_val) {
        int tmp[3] = {s, p_val, a_val};
        if (tmp[0] < tmp[1]) swap(tmp[0], tmp[1]);
        if (tmp[1] < tmp[2]) swap(tmp[1], tmp[2]);
        if (tmp[0] < tmp[1]) swap(tmp[0], tmp[1]);

        int cx = tmp[0];
        int cy = tmp[1];
        int cz = tmp[2];

        if (cx == cy && cy == cz) {
            x = cx + 1;
            y = cx;
            z = -1;
        } else if (cx == cy) {
            x = cx + 1;
            y = cz;
            z = -1;
        } else if (cy == cz) {
            if (cx == cy + 1) {
                x = cx + 1;
                y = -1;
                z = -1;
            } else {
                x = cx;
                y = cy + 1;
                z = -1;
            }
        } else {
            x = cx;
            y = cy;
            z = cz;
        }
    }
    bool operator<(const Score& o) const {
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        return z < o.z;
    }
};

struct Person {
    Score base;
    int id, p_val, a_val;
    bool operator<(const Person& o) const {
        return base < o.base;
    }
};

int n;
int p[N], a[N], b[N], w[N];
Person people[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        people[i].base = Score(-1, p[i], a[i]);
        people[i].id = i;
        people[i].p_val = p[i];
        people[i].a_val = a[i];
    }

    sort(people + 1, people + 1 + n);

    for (int i = 1; i <= n; ++i) {
        Score t_best = Score(1, p[i], a[i]);
        int failures = 0; 
        int cur_s = n; 

        for (int j = 1; j <= n; ++j) {
            if (people[j].id == i) continue;

            if (!(Score(cur_s, people[j].p_val, people[j].a_val) < t_best)) {
                cur_s--;
            } else {
                failures++;
            }
        }
        b[i] = failures + 1;

        Score t_worst = Score(n, p[i], a[i]);
        int w_cnt = 0; 
        int cur_s_worst = 1; 

        for (int j = n; j >= 1; --j) {
            if (people[j].id == i) continue;

            if (Score(cur_s_worst, people[j].p_val, people[j].a_val) < t_worst) {
                w_cnt++;
                cur_s_worst++;
            }
        }

        w[i] = w_cnt + 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << b[i] << ' ' << w[i] << '\n';
    }

    return 0;
}
