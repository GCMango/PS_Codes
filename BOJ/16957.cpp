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

int N, M, arr[500][500], cnt[500][500];
pii dp[500][500];

pii dfs(int i, int j) {
    if (dp[i][j].x != -1) return dp[i][j];
    pii ans = {j, i};
    pii opt[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int k = 0; k < 8; ++k) {
        int ii = i + opt[k].y, jj = j + opt[k].x;
        if (ii >= 0 && ii < N && jj >= 0 && jj < M && arr[ii][jj] < arr[ans.y][ans.x])
            ans.y = ii, ans.x = jj;
    }
    if (ans.y == i && ans.x == j) return dp[i][j] = {j, i};
    return dp[i][j] = dfs(ans.y, ans.x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            pii ans = dfs(i, j);
            cnt[ans.y][ans.x]++;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << cnt[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
