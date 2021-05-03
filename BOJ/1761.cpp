#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int MAX_LVL = (int)floor(log2(40000));

int N, M;
vector<vector<p>> graph;
vector<vector<int>> par;
vector<int> depth;
vector<int> dist;

void solve(int cur, int pnode) {
    for (int i = 1; i <= MAX_LVL; ++i)
        par[cur][i] = par[par[cur][i - 1]][i - 1];

    for (auto next : graph[cur]) {
        if (next.x != pnode) {
            depth[next.x] = depth[cur] + 1;
            par[next.x][0] = cur;
            dist[next.x] = dist[cur] + next.y;
            solve(next.x, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    par.resize(N + 1, vector<int>(MAX_LVL + 1));
    depth.resize(N + 1, 0);
    dist.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    solve(1, 0);

    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        int ans_x = dist[a], ans_y = dist[b];
        if (depth[a] != depth[b]) {
            if (depth[a] >= depth[b])
                swap(a, b);

            for (int i = MAX_LVL; i >= 0; --i)
                if (depth[a] <= depth[par[b][i]])
                    b = par[b][i];
        }

        int lca = a;
        if (a != b) {
            for (int i = MAX_LVL; i >= 0; --i) {
                if (par[a][i] != par[b][i]) {
                    a = par[a][i];
                    b = par[b][i];
                }
                lca = par[a][i];
            }
        }
        cout << ans_x + ans_y - dist[lca] * 2 << "\n";
    }

    return 0;
}
