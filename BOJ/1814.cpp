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
vector<int> color;

void solve(int cur, int pnode) {
    for (int i = 0; i < M; ++i)
        dp[cur][i] = color[i];
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        for (int i = 0; i < M; ++i) {
            int mn = 1e9;
            for (int j = 0; j < M; ++j)
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
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> M;
    color.resize(M);
    for (int i = 0; i < M; ++i) cin >> color[i];
    sort(all(color));
    M = (int)floor(log2(M)) + 1;
    color = vector<int>(color.begin(), color.begin() + M);
    dp.resize(N + 1, vector<int>(M, 0));

    solve(1, 0);

    int mn = 1e9;
    for (int i = 0; i < M; ++i)
        mn = min(mn, dp[1][i]);
    cout << mn << '\n';

    return 0;
}
