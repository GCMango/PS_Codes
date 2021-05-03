#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

ll N;
ll sum = 0;
vector<vector<ll>> graph;
vector<ll> cnt, depth;

void solve(ll cur, ll pnode) {
    sum += depth[cur] * (N - 1);
    ll x = 0, y = 0;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        depth[next] = depth[cur] + 1;
        solve(next, cur);
        cnt[cur] += cnt[next];
        x += y * cnt[next];
        y += cnt[next];
    }
    cnt[cur]++;
    x += cnt[cur] - 1;
    sum -= depth[cur] * x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    cnt = depth = vector<ll>(N + 1, 0);
    for (ll i = 0; i < N - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    cout << sum << "\n";

    return 0;
}
