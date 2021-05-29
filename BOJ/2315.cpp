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

int N, M;
ll sum[1001], dp[1001][1001][2];
pll input[1001];

ll dfs(int l, int r, int f) {
    if (l == 1 && r == N) return 0;
    if (dp[l][r][f] != -1) return dp[l][r][f];

    int cur = f ? r : l;
    ll val = sum[N] - sum[r] + sum[l - 1], ans = 1e18;
    if (l > 1)
        ans = min(ans, dfs(l - 1, r, 0) + (input[cur].x - input[l - 1].x) * val);
    if (r < N)
        ans = min(ans, dfs(l, r + 1, 1) + (input[r + 1].x - input[cur].x) * val);
    return dp[l][r][f] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> input[i].x >> input[i].y;
        sum[i] = sum[i - 1] + input[i].y;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(M, M, 0) << '\n';

    return 0;
}
