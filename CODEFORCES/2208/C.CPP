#include <bits/stdc++.h>
using namespace std;
#define double long double
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<double,double>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
//        sort(a.begin(), a.end(), [](const pair<double,double> &a, const pair<double,double> &b) {
//            return a.first * b.second > b.first * a.second;
//        });
        double ans = 0;
//        for (pair<int,int> x : a) {
////            ans += tmp * x.first;
////            tmp *= (1 - x.second / (double)100);
//            ans = max(ans, x.first + (1.0 - x.second / (double)100.0)) * ans;
//        }
        for (int i = n - 1; i >= 0; --i) {
            ans = max(ans, a[i].first + (1.0 - a[i].second / 100.0) * ans);
//            ans = max(ans, a[i].first + (1.0 - a[i].second / (double)100.0)) * ans;
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}
