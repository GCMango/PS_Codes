#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int MAX_LVL = (int)floor(log2(100000));

int N, M;
vector<vector<p>> graph;
vector<vector<int>> par;
vector<int> depth;
vector<ll> dist;

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
    dist.resize(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    solve(1, 0);

    cin >> M;
    while (M--) {
        int n, a, b, c;
        cin >> n >> a >> b;
        int ans_a = a, ans_b = b;
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
        if (n == 1)
            cout << dist[ans_a] + dist[ans_b] - dist[lca] * 2 << "\n";
        else if (n == 2) {
            cin >> c;
            if (depth[ans_a] - depth[lca] < c) {
                int ans_c = depth[lca] + c - (depth[ans_a] - depth[lca]) - 1;
                for (int i = MAX_LVL; i >= 0; --i)
                    if (ans_c <= depth[par[ans_b][i]] && par[ans_b][i] != 0)
                        ans_b = par[ans_b][i];
                cout << ans_b << "\n";
            }
            else {
                int ans_c = depth[ans_a] - c + 1;
                for (int i = MAX_LVL; i >= 0; --i)
                    if (ans_c <= depth[par[ans_a][i]] && par[ans_a][i] != 0)
                        ans_a = par[ans_a][i];
                cout << ans_a << "\n";
            }
        }
    }

    return 0;
}
