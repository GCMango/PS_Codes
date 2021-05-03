#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int MAX_LVL = (int)floor(log2(100000));

struct Line {
    int n;
    int a = 1e9;
    int b = 0;
};

int N, K;
vector<vector<p>> graph;
vector<vector<Line>> par;
vector<int> depth;

void solve(int cur, int pnode) {
    for (int i = 1; i <= MAX_LVL; ++i) {
        par[cur][i].n = par[par[cur][i - 1].n][i - 1].n;
        par[cur][i].a = min(par[cur][i - 1].a, par[par[cur][i - 1].n][i - 1].a);
        par[cur][i].b = max(par[cur][i - 1].b, par[par[cur][i - 1].n][i - 1].b);
    }

    for (auto next : graph[cur]) {
        if (next.x != pnode) {
            depth[next.x] = depth[cur] + 1;
            par[next.x][0].n = cur;
            par[next.x][0].a = par[next.x][0].b = next.y;
            solve(next.x, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N + 1);
    par.resize(N + 1, vector<Line>(MAX_LVL + 1));
    depth.resize(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    solve(1, 0);

    cin >> K;
    while (K--) {
        int a, b;
        cin >> a >> b;
        int mn = 1e9, mx = 0;
        if (depth[a] != depth[b]) {
            if (depth[a] >= depth[b])
                swap(a, b);
            for (int i = MAX_LVL; i >= 0; --i) {
                if (depth[a] <= depth[par[b][i].n]) {
                    mn = min(mn, par[b][i].a);
                    mx = max(mx, par[b][i].b);
                    b = par[b][i].n;
                }
            }
        }
        if (a != b) {
            for (int i = MAX_LVL; i >= 0; --i) {
                if (par[a][i].n != par[b][i].n) {
                    mn = min(mn, min(par[a][i].a, par[b][i].a));
                    mx = max(mx, max(par[a][i].b, par[b][i].b));
                    a = par[a][i].n;
                    b = par[b][i].n;
                }
            }
            mn = min(mn, min(par[a][0].a, par[b][0].a));
            mx = max(mx, max(par[a][0].b, par[b][0].b));
        }
        cout << mn << ' ' << mx << "\n";
    }

    return 0;
}
