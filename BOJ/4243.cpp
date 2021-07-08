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

int N, S;
ll arr[100], dp[100][100][2];

ll dfs(int s, int e, int pos) {
    if (s == 0 && e == N - 1) return 0;
    ll &ret = dp[s][e][pos];
    if (ret) return ret;
    ret = 1e18;
    int cur = (pos ? e : s), cnt = N - (e - s + 1);
    if (s > 0)
        ret = min(ret, dfs(s - 1, e, 0) + (arr[cur] - arr[s - 1]) * cnt);
    if (e < N - 1)
        ret = min(ret, dfs(s, e + 1, 1) + (arr[e + 1] - arr[cur]) * cnt);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        cin >> N >> S; S--;
        ll cur = 0;
        for (int i = 1; i < N; ++i) {
            ll n; cin >> n;
            cur += n;
            arr[i] = cur;
        }
        cout << dfs(S, S, 0) << '\n';
    }

    return 0;
}
