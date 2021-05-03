#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, M;
vector<int> visited;

int solve(int x, vector<vector<int>> arr) {
    int ret = 0;

    queue<int> que;
    que.push(x);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        if (visited[cur]) continue;
        ret++;
        visited[cur] = 1;
        for (int i = 0; i < arr[cur].size(); ++i) {
            int next = arr[cur][i];
            if (visited[next] == 0)
                que.push(next);
        }
    }

    for (int i = 1; i <= N; ++i) visited[i] = 0;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<vector<int>> higher(N + 1);
    vector<vector<int>> lower(N + 1);
    visited.resize(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        higher[b].push_back(a);
        lower[a].push_back(b);
    }

    int result = 0;
    for (int i = 1; i <= N; ++i) {
        int higher_val = solve(i, higher);
        int lower_val = solve(i, lower);
        if (higher_val == N - lower_val + 1) result++;
    }

    cout << result << "\n";

    return 0;
}
