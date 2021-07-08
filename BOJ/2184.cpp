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

int N, arr[1111], dp[1111][1111][2];

int dfs(int s, int e, int p) {
    if (s == 0 && e == N - 1) return 0;
    int &ret = dp[s][e][p];
    if (ret != -1) return ret;
    ret = 1e9;
    int cur = p ? e : s, cnt = N - (e - s + 1);
    if (s > 0)
        ret = min(ret, dfs(s - 1, e, 0) + (arr[cur] - arr[s - 1]) * cnt);
    if (e < N - 1)
        ret = min(ret, dfs(s, e + 1, 1) + (arr[e + 1] - arr[cur]) * cnt);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> N; N++;
    int S; cin >> S;
    arr[0] = S;
    for (int i = 1; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    int pos = lower_bound(arr, arr + N, S) - arr;
    cout << dfs(pos, pos, 0) << '\n';

    return 0;
}
