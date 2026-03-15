// https://oj.vnoi.info/problem/bedao_r23_e#submit
#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 3e5 + 5;
int n, dp[N];
pair<int,int> a[N];
map<pair<int,int>,bool> mp;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n / 2; ++i) {
        int x, y;
        cin >> x >> y;
        mp[{x, y}] = true;
        mp[{y, x}] = true;
    }

    fill(dp, dp + N, 1e18);
    dp[0] = 0;
    for (int i = 2; i <= n; i += 2) {
        int idx = a[i].second;
        int idx1 = a[i - 1].second;
        int idx2 = (i >= 4 ? a[i - 2].second : 0);
        int idx3 = (i >= 4 ? a[i - 3].second : 0);
        
        if (!mp.count({idx, idx1})) {
            dp[i] = dp[i - 2] + (a[i].first - a[i - 1].first);
        } 
        if (i >= 4 && !mp.count({idx, idx2}) && !mp.count({idx1, idx3})) {
            dp[i] = min(dp[i], dp[i - 4] + (a[i].first - a[i - 2].first) + (a[i - 1].first - a[i - 3].first));
        }
        if (i >= 4 && !mp.count({idx, idx3}) && !mp.count({idx1, idx2})) {
            dp[i] = min(dp[i], dp[i - 4] + (a[i].first - a[i - 3].first) + (a[i - 1].first - a[i - 2].first));
        }
    }
    cout << dp[n];

    return 0;
}