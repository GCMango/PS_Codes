#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N;
vector<vector<int>> graph;
vector<vector<int>> dp;

void solve(int cur, int pnode) {
    dp[cur][1] = 1;
    for (auto next : graph[cur]) {
        if (next != pnode) {
            solve(next, cur);
            dp[cur][0] += dp[next][1];
            dp[cur][1] += min(dp[next][0], dp[next][1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    dp.resize(N + 1, vector<int>(2, 0));
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
