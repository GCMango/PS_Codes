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
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<int> cnt;

void solve(int cur, int pnode) {
    dp[cur][0] = 0;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        cnt[cur] += cnt[next];
        int sze = cnt[next];
        for (int i = cnt[cur] - 1; i >= sze; --i)
            dp[cur][i] = min(dp[cur][i], dp[cur][i - sze] + 1);
        for (int i = 1; i <= cnt[next]; ++i) dp[cur][i] = min(dp[cur][i], dp[next][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    cnt.resize(N + 1, 1);
    dp.resize(N + 1, vector<int>(N + 1, 200));
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    for (int i = 1; i <= N; ++i) {
        int mn = min(dp[1][i], dp[1][N - i]);
        cout << (mn == 200 ? -1 : mn) << "\n";
    }

    return 0;
}
