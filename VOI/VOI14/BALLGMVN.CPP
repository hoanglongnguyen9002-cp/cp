#include <bits/stdc++.h>
using namespace std;

const int N = 1001 * 2;
int n;
struct Ball {
    int x, y, c, idx;
} a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].c = 0;
        a[i].idx = i;
    }
    for (int i = n + 1; i <= 2 * n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].c = 1;
        a[i].idx = i;
    }
    for (int i = 1; i <= 2 * n; ++i) {
        map<pair<int,int>,vector<int>> mp;
        for (int j = i + 1; j <= 2 * n; ++j) {
            int dx = abs(a[j].x - a[i].x);
            int dy = abs(a[j].y - a[i].y);
            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;
            mp[{dx, dy}].push_back(j);
        }
        for (pair<pair<int,int>,vector<int>> tmp : mp) {
            vector<int> point = tmp.second;
            point.push_back(i);
            vector<int> blue, red;
            for (int x : point) {
                if (a[x].c == 0) blue.push_back(x);
                else red.push_back(x);
            }
            if (blue.size() >= 2 && red.size() >= 1) {
                cout << a[blue[0]].idx << ' ' << a[blue[1]].idx << ' ' << a[red[0]].idx;
                return 0;
            }
            if (blue.size() >= 1 && red.size() >= 2) {
                cout << a[red[0]].idx << ' ' << a[red[1]].idx << ' ' << a[blue[0]].idx;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
