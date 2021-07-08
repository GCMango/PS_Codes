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

    int N, K, M; cin >> N >> K >> M;
    vector<vector<int>> graph(N + M + 1);
    vector<int> cost(N + M + 1, 0);
    for (int i = 0; i < M; ++i) {
        int tube = N + i + 1;
        for (int j = 0; j < K; ++j) {
            int n; cin >> n;
            graph[tube].push_back(n);
            graph[n].push_back(tube);
        }
    }
    queue<int> q; q.push(1);
    cost[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == N) break;
        for (auto i : graph[cur]) {
            if (cost[i]) continue;
            cost[i] = cost[cur] + 1;
            q.push(i);
        }
    }
    cout << (cost[N] ? cost[N] - cost[N] / 2 : -1) << '\n';

    return 0;
}

