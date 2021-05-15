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

int N, M;
vector<vector<int>> graph;
vector<int> ch;

void solve(int cur) {
    for (auto next : graph[cur]) {
        ch[next] += ch[cur];
        solve(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    ch.resize(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int n;
        cin >> n;
        if (n == -1) continue;
        graph[n].push_back(i);
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        ch[a] += b;
    }
    
    solve(1);

    for (int i = 1; i <= N; ++i) cout << ch[i] << ' ';
    cout << '\n';

    return 0;
}
