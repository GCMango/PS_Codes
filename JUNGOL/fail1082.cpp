#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> input(N, vector<int>(M));
    vector<vector<int>> arr(N, vector<int>(M, INF));
    queue<p> que;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') que.push({j, i});
        }
    }

    while (!que.empty()) {
        p cur = que.front();
        que.pop();
    }

    return 0;
}
