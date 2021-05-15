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
int depth[100001], dp[100001][2];
vector<vector<int>> graph;

void init_tree(int cur, int pnode) {
    dp[cur][depth[cur] % 2]++;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        depth[next] = depth[cur] + 1;
        init_tree(next, cur);
        dp[cur][0] += dp[next][0];
        dp[cur][1] += dp[next][1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    init_tree(1, 0);

    while (M--) {
        int u, v, c;
        ll ans;
        cin >> u >> v >> c;
        if (depth[u] < depth[v])
            swap(u, v);
        int a1 = dp[u][0], a2 = dp[u][1], b1 = dp[1][0] - a1, b2 = dp[1][1] - a2;
        if (c == 0)
            ans = 1LL * a1 * b1 + 1LL * a2 * b2;
        else
            ans = 1LL * a1 * b2 + 1LL * a2 * b1;
        cout << ans << '\n';
    }

    return 0;
}
