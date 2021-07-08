#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MXN = 3003;
int N, M, a, b, arr[MXN], dp[MXN][MXN];

int dfs(int i, int j) {
    if (i >= M || j >= M) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int next = max(i, j) + 1, res = 1e9;
    int tmp = a;
    a = arr[next];
    res = min(res, dfs(next, j) + abs(tmp - arr[next]));
    a = tmp;
    tmp = b;
    b = arr[next];
    res = min(res, dfs(i, next) + abs(tmp - arr[next]));
    b = tmp;
    return dp[i][j] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> a >> b >> M;
    for (int i = 1; i <= M; ++i) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';

    return 0;
}

