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

vector<vector<int>> graph;
vector<vector<int>> par;
vector<int> depth;

void solve(int cur, int pnode) {
    depth[cur] = depth[pnode] + 1;
    par[cur][0] = pnode;

    for (int i = 1; i <= MAX_LVL; ++i) {
        int tmp = par[cur][i - 1];
        par[cur][i] = par[tmp][i - 1];
    }

    for (int i = 0; i < graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if (next != pnode)
            solve(next, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    graph.resize(N + 1);
    par.resize(N + 1, vector<int>(MAX_LVL, 0));
    depth.resize(N + 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b])
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

        cout << lca << "\n";
    }

    return 0;
}


