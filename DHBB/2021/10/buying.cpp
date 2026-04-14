#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sumA = 0, sumB = 0, sumC = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        sumA += a;
        sumB += b - i + 1;
        sumC += c - i + 1;
    }
    cout << min({sumA, sumB, sumC});
    return 0;
}
