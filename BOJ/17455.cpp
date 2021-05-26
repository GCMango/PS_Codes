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

int N, M, input[300003], dp[300003];
vector<vector<int>> graph;
queue<pii> que;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(M + 2);
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        switch (c) {
            case 'K':
                input[i] = 1;
                break;
            case 'D':
                input[i] = 2;
                break;
            default:
                input[i] = 3;
        }
    }
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int mx = 0, r = 0;
    if (input[1] == 1) r = 1;
    que.push({1, r});
    while (!que.empty()) {
        pii cur = que.front();
        que.pop();
        if (input[cur.x] == 3) {
            dp[cur.x] = max(dp[cur.x], dp[cur.y] + 1);
            mx = max(mx, dp[cur.x]);
            continue;
        }
        for (auto next : graph[cur.x]) {
            int r = dp[cur.x];
            if (input[next] == 1 || (input[next] == input[cur.x] + 1 && input[cur.y] == input[cur.x] - 1))
                r++;
            if (r <= dp[next]) continue;
            dp[next] = r;
            que.push({next, cur.x});
        }
    }

    cout << mx << '\n';

    return 0;
}
