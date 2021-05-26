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

int N, M, cnt = 0, dp[200001][3];
bool check[200001];
vector<vector<int>> graph;

void solve(int cur, int pnode) {
    dp[cur][2] = 1;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        dp[cur][0] += min(dp[next][1], dp[next][2]);
        dp[cur][1] += min(dp[next][2], dp[next][0]);
        dp[cur][2] += min(dp[next][0], dp[next][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        check[a] = true;
        check[b] = true;
    }

    solve(1, 0);

    for (int i = 1; i <= N; ++i)
        if (!check[i])
            cnt++;

    cout << min({dp[1][0], dp[1][1], dp[1][2]}) + cnt << '\n';

    return 0;
}
