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

const int MAX_LVL = (int)floor(log2(100000));

int N, M, ans_a, ans_b;
vector<vector<int>> graph;
vector<pii> par;
vector<int> depth;

void init_tree(int cur, int pnode) {
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        depth[next] = depth[cur] + 1;
        par[next].x = cur;
        init_tree(next, cur);
    }
}

void get_lca(int a, int b, int option) {
    ans_a = ans_b = 0;
    if (depth[a] >= depth[b])
        swap(a, b);
    while (depth[a] != depth[b]) {
        if (option == 1)
            par[b].y++;
        else
            ans_b += par[b].y;
        b = par[b].x;
    }
    while (a != b && a != 0 && b != 0) {
        if (option == 1) {
            par[a].y++;
            par[b].y++;
        }
        else {
            ans_a += par[a].y;
            ans_b += par[b].y;
        }
        a = par[a].x;
        b = par[b].x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    par.resize(N + 1);
    depth.resize(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    init_tree(1, 0);

    while (M--) {
        char c; cin >> c;
        int a, b; cin >> a >> b;
        if (c == 'P')
            get_lca(a, b, 1);
        else if (c == 'Q') {
            get_lca(a, b, 2);
            cout << ans_a + ans_b << "\n";
        }
    }

    return 0;
}
