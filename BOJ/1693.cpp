#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, max_num;
vector<vector<int>> graph;
vector<vector<int>> dp;

void solve(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        for (int i = 1; i <= max_num; ++i) {
            int mn = 1e9;
            for (int j = 1; j <= max_num; ++j)
                if (i != j)
                    mn = min(mn, dp[next][j]);
            dp[cur][i] += mn;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    max_num = (int)floor(log2(N));
    graph.resize(N + 1);
    dp.resize(N + 1, vector<int>(max_num + 1));
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i <= N; ++i)
        for (int j = 1; j <= max_num; ++j)
            dp[i][j] = j;

    solve(1, 0);

    int mn = 1e9;
    for (int i = 1; i <= max_num; ++i)
        mn = min(mn, dp[1][i]);
    cout << mn << "\n";

    return 0;
}

