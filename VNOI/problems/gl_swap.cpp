// https://oj.vnoi.info/problem/gl_swap#submit
#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int INF = 1e9;
int n, a[5][N], b[5][N], dp[N][N][N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
   
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[1][i] == 0) cnt1++;
        if (a[2][i] == 0) cnt2++;
        if (a[3][i] == 0) cnt3++;
    }

    for (int i = 1; i <= n; ++i) { 
        for (int x = 0; x <= n; ++x) {
            for (int y = 0; y <= n; ++y) {
                for (int z = 0; z <= n; ++z) {
                    dp[i][x][y][z] = -INF;
                }
            }
        }
    }

    int pos1 = 0, pos2 = 0, pos3 = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[1][i] != 0) b[1][++pos1] = a[1][i];
        if (a[2][i] != 0) b[2][++pos2] = a[2][i];
        if (a[3][i] != 0) b[3][++pos3] = a[3][i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int x = 0; x <= cnt1; ++x) {
            for (int y = 0; y <= cnt2; ++y) {
                for (int z = 0; z <= cnt3; ++z) {
                    dp[i][x][y][z] = max(dp[i][x][y][z], dp[i - 1][x][y][z] + b[1][i - x] * b[2][i - y] * b[3][i - z]);
                    dp[i][x + 1][y][z] = max(dp[i][x + 1][y][z], dp[i - 1][x][y][z]);
                    dp[i][x][y + 1][z] = max(dp[i][x][y + 1][z], dp[i - 1][x][y][z]);
                    dp[i][x][y][z + 1] = max(dp[i][x][y][z + 1], dp[i - 1][x][y][z]);
                    dp[i][x + 1][y + 1][z] = max(dp[i][x + 1][y + 1][z], dp[i - 1][x][y][z]);
                    dp[i][x + 1][y][z + 1] = max(dp[i][x + 1][y][z + 1], dp[i - 1][x][y][z]);
                    dp[i][x][y + 1][z + 1] = max(dp[i][x][y + 1][z + 1], dp[i - 1][x][y][z]);
                    dp[i][x + 1][y + 1][z + 1] = max(dp[i][x + 1][y + 1][z + 1], dp[i - 1][x][y][z]);
                    // cerr << i << ' ' << x << ' ' << y << ' ' << z << ' ' << dp[i][x][y][z] << endl;
                }
            }
        }
    }
    
    cout << dp[n][cnt1][cnt2][cnt3];
    return 0;
}