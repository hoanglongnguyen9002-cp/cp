#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 55;
int vs[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        fill(vs, vs + N, 0);
        int cur = 1;
        for (int i = 0; i <= n; i++) {
            vs[cur] = 1;
            if (s[cur - 1] == 'L') cur--;
            else cur++;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) ans += vs[i];
        cout << ans << '\n';
    }
    return 0;
}
