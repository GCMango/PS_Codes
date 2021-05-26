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

int N, M, dp[1001];
vector<vector<pii>> graph;

void solve(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next.x == pnode) continue;
        solve(next.x, cur);
        if (dp[next.x] == 0) dp[next.x] = next.y;
        dp[cur] += min(next.y, dp[next.x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        graph.clear();
        graph.resize(N + 1);
        fill(dp, dp + 1000, 0);
        for (int i = 0; i < M; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        solve(1, 0);
        cout << dp[1] << '\n';
    }

    return 0;
}
