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

int N, cnt[300001];
ll dp[300001];
vector<vector<pii>> graph;

void init_tree(int cur, int pnode) {
    cnt[cur] = 1;
    for (auto next : graph[cur]) {
        if (next.x == pnode) continue;
        init_tree(next.x, cur);
        cnt[cur] += cnt[next.x];
        dp[cur] += dp[next.x] + cnt[next.x] * next.y;
    }
}

void get_val(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next.x == pnode) continue;
        dp[next.x] = dp[cur] - cnt[next.x] * next.y + (N - cnt[next.x]) * next.y;
        get_val(next.x, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    init_tree(1, 0);
    get_val(1, 0);

    for (int i = 1; i <= N; ++i) cout << dp[i] << '\n';

    return 0;
}
