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

int N, W, arr[10000][2], dp[10000][3];

int dfs(int n, int s, int c) {
    if (n == N) return 0;
    if (n == N - 1) {
        if (!c) {
            if (s) return 1;
            return arr[n][0] + arr[n][1] <= W ? 1 : 2;
        }
        if (c == 3) return 0;
        if (s == c || !s) return 1;
        return 0;
    }
    int &ret = dp[n][s];
    if (ret != -1) return ret;
    ret = 1e9;
    if (s == 0) {
        ret = min(dfs(n, 1, c), dfs(n, 2, c)) + 1;
        ret = min(ret, dfs(n + 1, 0, c) + (arr[n][0] + arr[n][1] <= W ? 1 : 2));
        if (arr[n][0] + arr[n + 1][0] <= W && arr[n][1] + arr[n + 1][1] <= W)
            ret = min(ret, dfs(n + 2, 0, c) + 2);
    }
    else {
        ret = dfs(n + 1, 0, c) + 1;
        if (arr[n][2 - s] + arr[n + 1][2 - s] <= W)
            ret = min(ret, dfs(n + 1, 3 - s, c) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        memset(dp, -1, sizeof(dp));
        cin >> N >> W;
        for (int i = 0; i < N; ++i) cin >> arr[i][0];
        for (int i = 0; i < N; ++i) cin >> arr[i][1];
        int ans = dfs(0, 0, 0);
        if (arr[0][0] + arr[N - 1][0] <= W) {
            memset(dp, -1, sizeof(dp));
            ans = min(ans, dfs(0, 1, 1) + 1);
        }
        if (arr[0][1] + arr[N - 1][1] <= W) {
            memset(dp, -1, sizeof(dp));
            ans = min(ans, dfs(0, 2, 2) + 1);
        }
        if (arr[0][0] + arr[N - 1][0] <= W && arr[0][1] + arr[N - 1][1] <= W) {
            memset(dp, -1, sizeof(dp));
            ans = min(ans, dfs(1, 0, 3) + 2);
        }
        cout << ans << '\n';
    }

    return 0;
}
