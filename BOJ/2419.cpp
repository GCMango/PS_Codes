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

int N, M, S, arr[333];
ll dp[333][333][2];

ll dfs(int s, int e, int pos, int cnt) {
    if (!cnt) return 0;
    ll &ret = dp[s][e][pos];
    if (ret != -1) return ret;
    ret = 1e18;
    int cur = pos ? e : s;
    if (s > 0)
        ret = min(ret, dfs(s - 1, e, 0, cnt - 1) + (arr[cur] - arr[s - 1]) * cnt);
    if (e < N - 1)
        ret = min(ret, dfs(s, e + 1, 1, cnt - 1) + (arr[e + 1] - arr[cur]) * cnt);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M; N++;
    for (int i = 1; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    S = lower_bound(arr, arr + N, 0) - arr;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        memset(dp, -1, sizeof(dp));
        ans = max(ans, 1LL * M * i - dfs(S, S, 0, i));
    }
    cout << ans << '\n';

    return 0;
}
