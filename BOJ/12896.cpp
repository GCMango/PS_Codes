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

int N, M, root;
vector<vector<int>> graph;

int solve(int cur) {
    if (cur == M) return 0;
    int ans = 0;
    for (auto next : graph[cur])
        ans += solve(next);
    return ans == 0 ? 1 : ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.resize(N);
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n == -1) root = i;
        else graph[n].push_back(i);
    }
    cin >> M;
    cout << solve(root) << '\n';

    return 0;
}
