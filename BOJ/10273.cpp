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

int N, E, cost[20002];
pii dp[20002];
vector<vector<pii>> graph;

void solve(int cur, int pnode) {
    int idx = 0;
    for (int i = 0; i < graph[cur].size(); ++i) {
        pii next = graph[cur][i];
        if (next.x == pnode || next.x == cur) continue;
        solve(next.x, cur);
        if (dp[idx].x - graph[cur][idx].y < dp[next.x].x - next.y)
            idx = i;
    }
    dp[cur].x = cost[cur] + dp[graph[cur][idx].x].x - graph[cur][idx].y;
    dp[cur].y = graph[cur][idx].x;
    if (dp[cur].y == cur) dp[cur].y = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> E;
        fill(cost, cost + N + 1, 0);
        for (int i = 0; i <= N; ++i) dp[i].x = dp[i].y = 0;
        graph.clear();
        graph.resize(N + 1);
    
        for (int i = 1; i <= N; ++i) {
            cin >> cost[i];
            graph[i].push_back({i, 0});
        }
        for (int i = 0; i < E; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
    
        solve(1, 0);
    
        vector<int> ans;
        int idx = 1;
        while (idx != 0) {
            ans.push_back(idx);
            idx = dp[idx].y;
        }
        
        cout << dp[1].x << ' ' << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
