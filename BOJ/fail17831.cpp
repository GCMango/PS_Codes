#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N;
vector<vector<ll>> graph;
vector<ll> skill, mxs;
vector<vector<ll>> dp;

void solve(int cur) {
    ll max_idx = -1;
    ll max_val = -1;
    ll sum = 0;
    for (auto next : graph[cur]) {
        solve(next);
        mxs[next] = max(dp[next][0], dp[next][1]);
        sum += mxs[next];
    }
    for (auto next : graph[cur]) {
        int minus = 0;
        if (dp[next][1] > dp[next][0]) minus = abs(dp[next][0] - dp[next][1]);
        int comp = sum - minus + skill[cur] * skill[next];
        if (comp > max_val) {
            max_val = comp;
            max_idx = next;
        }
    }
    for (auto next : graph[cur]) {
        if (next == max_idx)
            dp[cur][1] += skill[next] * skill[cur] + dp[next][0];
        else
            dp[cur][1] += max(dp[next][0], dp[next][1]);
        dp[cur][0] += max(dp[next][0], dp[next][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    skill = mxs = vector<ll>(N + 1);
    dp.resize(N + 1, vector<ll>(2, 0));

    for (int i = 2; i <= N; ++i) {
        ll n;
        cin >> n;
        graph[n].push_back(i);
    }
    for (int i = 1; i <= N; ++i)
        cin >> skill[i];

    solve(1);

    for (int i = 1; i <= N; ++i) cout << dp[i][0] << ' ' << dp[i][1] << "\n";

    return 0;
}
