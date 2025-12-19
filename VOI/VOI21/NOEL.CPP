#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n, d, c[N * 2], pos[N * 2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= 2 * n; ++i) cin >> c[i], pos[c[i]] = i;
    int ans = 0;
    for (int mid = 1; mid <= 2 * n; ++mid) {
        vector<int> dp;
        for (int left = 1; left <= mid; ++left) {
            vector<int> candidate;
            for (int cand = max(1, c[left] - d); cand <= min(2 * n, c[left] + d); ++cand) {
                if (pos[cand] > mid) candidate.push_back(pos[cand]);
            }
            sort(candidate.begin(), candidate.end(), greater<int>());
            for (int right : candidate) {
                auto it = lower_bound(dp.begin(), dp.end(), right);
                if (it == dp.end()) dp.push_back(right);
                else *it = right;
            }
        }
        ans = max(ans, (int)dp.size());
    }
    cout << ans;
    return 0;
}

