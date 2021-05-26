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

int N, w[10001], dp[10001][2][2];
vector<vector<int>> graph;

void solve(int cur, int pnode) {
    dp[cur][1] = w[cur];
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    for (int i = 1; i <= N; ++i) cin >> w[i];
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
