#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N;
vector<vector<int>> dp;
vector<vector<int>> node;

void solve(int cur, int pnode) {
    for (auto next : node[cur]) {
        if (next != pnode) {
            solve(next, cur);
            dp[cur][0] += max(dp[next][0], dp[next][1]);
            dp[cur][1] += dp[next][0];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    dp.resize(N + 1, vector<int>(2, 0));
    node.resize(N + 1);
    for (int i = 1; i <= N; ++i) cin >> dp[i][1];

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    solve(1, 0);

    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}

