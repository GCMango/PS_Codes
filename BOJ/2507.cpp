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

const int MOD = 1000;

int N, loc[500], dist[500], dp[500][500];
bool b[500];

int dfs(int s, int e) {
    if (s == N - 1)
        return loc[s] - loc[e] <= dist[s];
    if (dp[s][e] != -1) return dp[s][e];

    int ans = 0, next = max(s, e) + 1;
    for (int i = next; i < N; ++i) {
        if (loc[i] - loc[s] <= dist[s])
            ans = (ans + dfs(i, e)) % MOD;
        if (loc[i] - loc[e] <= dist[i] && b[i])
            ans = (ans + dfs(s, i)) % MOD;
    }

    return dp[s][e] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> loc[i] >> dist[i] >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';

    return 0;
}
