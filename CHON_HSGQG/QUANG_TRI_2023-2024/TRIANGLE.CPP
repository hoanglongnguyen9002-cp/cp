#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> stick[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("TRIANGLE.INP", "r", stdin);
    freopen("TRIANGLE.OUT", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'b') stick[0].push_back(x);
        if (c == 'g') stick[1].push_back(x);
        if (c == 'r') stick[2].push_back(x);
    }

    sort(stick, stick + 3, [](const vector<int> &a, const vector<int>&b) {
        return a.size() < b.size();
    });
    sort(stick[0].begin(), stick[0].end());
    sort(stick[1].begin(), stick[1].end());
    sort(stick[2].begin(), stick[2].end());

//    for (int i = 0; i < 3; ++i) {
//        for (int x : stick[i]) cout << x << ' ';
//        cout << endl;
//    }

    ll ans = 0;
    for (int x : stick[0]) {
        for (int y : stick[1]) {
            int l = upper_bound(stick[2].begin(), stick[2].end(), abs(x - y)) - stick[2].begin();
            int r = lower_bound(stick[2].begin(), stick[2].end(), x + y) - stick[2].begin() - 1;
            ans += (r - l + 1);
        }
    }
    cout << ans << '\n';


    return 0;
}
