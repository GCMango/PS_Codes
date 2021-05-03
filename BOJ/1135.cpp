#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N;
vector<vector<int>> graph;
vector<int> dp;

void solve(int cur) {
    vector<int> v;
    for (auto next : graph[cur]) {
        solve(next);
        v.push_back(dp[next]);
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < v.size(); ++i)
        dp[cur] = max(dp[cur], v[i] + i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N);
    dp.resize(N, 0);
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n == -1) continue;
        graph[n].push_back(i);
    }

    solve(0);

    cout << dp[0] << "\n";

    return 0;
}
