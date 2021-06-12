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

int N, K, dp[300003][2];
vector<vector<int>> graph;

void dfs(int cur, int pnode) {
    dp[cur][1] = 1;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        dfs(next, cur);
        dp[cur][0] += dp[next][0];
    }

    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        int x = dp[next][0] + (dp[next][1] >= K);
        int y = (dp[next][1] + 1) % K;
        if ()
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    K++;
    graph.resize(N + 1);
    memset(dp, 1e9, sizeof(dp));
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << dp[1][0] << '\n';

    return 0;
}
