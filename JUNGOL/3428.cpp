#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, M, X;
vector<vector<int>> higher;
vector<vector<int>> lower;
vector<int> visited;

int solve(vector<vector<int>> arr) {
    int ret = 0;

    queue<int> que;
    que.push(X);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        if (visited[cur]) continue;
        ret++;
        visited[cur] = 1;
        for (int i = 0; i < arr[cur].size(); ++i) {
            int ii = arr[cur][i];
            if (visited[ii] == 0)
                que.push(ii);
        }
    }

    for (int i = 1; i <= N; ++i) visited[i] = 0;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> X;
    higher.resize(N + 1);
    lower.resize(N + 1);
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        lower[a].push_back(b);
        higher[b].push_back(a);
    }

    int higher_val = solve(higher);
    int lower_val = solve(lower);

    cout << higher_val << ' ' << N - lower_val + 1 << "\n";

    return 0;
}
