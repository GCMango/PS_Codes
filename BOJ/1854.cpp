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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    struct Comp { bool operator()(pii &a, pii &b) { return a.y > b.y; } };
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pii>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    priority_queue<pii, vector<pii>, Comp> pq;
    vector<priority_queue<int>> min_cost(N + 1);
    pq.push({1, 0}); min_cost[1].push(0);
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        for (auto i : graph[cur.x]) {
            if (min_cost[i.x].size() < K) {
                min_cost[i.x].push(cur.y + i.y);
                pq.push({i.x, cur.y + i.y});
            }
            else if (cur.y + i.y < min_cost[i.x].top()) {
                min_cost[i.x].pop();
                min_cost[i.x].push(cur.y + i.y);
                pq.push({i.x, cur.y + i.y});
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (min_cost[i].size() < K) cout << "-1\n";
        else cout << min_cost[i].top() << '\n';
    }

    return 0;
}
