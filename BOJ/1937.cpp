#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, mx = 0;
vector<vector<int>> input;
vector<vector<int>> dp;
vector<pii> option{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solve(int y, int x) {
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int yy = y + option[i].y, xx = x + option[i].x;
        if (yy >= 0 && yy < N && xx >= 0 && xx < N && input[y][x] < input[yy][xx]) {
            if (dp[yy][xx] != 0)
                ans = max(ans, dp[yy][xx]);
            else
                ans = max(ans, solve(yy, xx));
        }
    }
    return dp[y][x] = ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    input = dp = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> input[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (dp[i][j] == 0)
                mx = max(mx, solve(i, j));

    cout << mx << '\n';

    return 0;
}
