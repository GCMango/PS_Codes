#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

struct Grid {
    int x;
    int y;
    int n;
};

int dp[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, mxx = 0, mxy = 0;
    cin >> T;
    vector<Grid> cases(T);
    for (int i = 0; i < T; ++i) {
        cin >> cases[i].y >> cases[i].x >> cases[i].n;
        mxx = max(mxx, cases[i].x);
        mxy = max(mxy, cases[i].y);
    }

    dp[1][1] = 0;
    for (int i = 2; i <= mxx; ++i)
        dp[1][i] = dp[1][i - 1] + 1;
    for (int i = 2; i <= mxy; ++i)
        dp[i][1] = dp[i - 1][1] + 1;

    for (int i = 2; i <= mxy; ++i)
        for (int j = 2; j <= mxx; ++j)
            dp[i][j] = min(dp[i - 1][j] + j, dp[i][j - 1] + i);

    for (int i = 0; i < T; ++i) {
        if (dp[cases[i].y][cases[i].x] == cases[i].n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
