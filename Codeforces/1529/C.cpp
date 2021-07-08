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

int N;
ll input[100001][2], dp[100001][2];
vector<vector<int>> graph;

void dfs(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        dfs(next, cur);
        dp[cur][0] += max(abs(input[cur][0] - input[next][0]) + dp[next][0], abs(input[cur][0] - input[next][1]) + dp[next][1]);
        dp[cur][1] += max(abs(input[cur][1] - input[next][0]) + dp[next][0], abs(input[cur][1] - input[next][1]) + dp[next][1]);
    }
}

void solve() {
    cin >> N;
    graph.clear();
    graph.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> input[i][0] >> input[i][1];
        dp[i][0] = dp[i][1] = 0;
    }
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
