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

int N, K;
vector<vector<int>> graph;
vector<vector<int>> dp;

void solve(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next == pnode) continue;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    graph.resize(N + 1);
    dp.resize(N + 1, vector<int>(K + 1, 1));
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    solve(1, 0);

    cout << dp[1][K] << '\n';

    return 0;
}
