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

const ll MOD = 1e9 + 7;

int N, K, cnt[51];
ll dp[51][51];
vector<vector<int>> graph;

void solve(int cur, int pnode) {
    cnt[cur] = dp[cur][1] = 1;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        cnt[cur] += cnt[next];
        for (int i = 2; i <= K; ++i)
            dp[cur][i] += dp[next][i - 1];
    }
    int sze = graph[cur].size();
    for (int ii = 0; ii < sze; ++ii) {
        for (int jj = ii + 1; jj < sze; ++jj) {
            int i = graph[cur][ii], j = graph[cur][jj];
            if (i == pnode || j == pnode) continue;
            for (int k = 3; k <= K; ++k)
                for (int r = 1; r < k; ++r)
                    dp[cur][k] += dp[i][r] * dp[j][k - r - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    graph.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    ll sum = 0;
    for (int i = 1; i <= N; ++i) sum += dp[i][K];
    cout << sum % MOD << '\n';

    return 0;
}
