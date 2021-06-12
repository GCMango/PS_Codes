#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, M;
vector<vector<int>> arr;
vector<vector<vector<int>>> mx;
vector<vector<vector<bool>>> visited;
vector<p> option{{1, 0}, {0, 1}, {0, -1}};

void solve(int a, int b, int cnt, int path) {
    if (path == 3) {
        mx[a][b][0] = mx[a][b][1] = mx[a][b][2] = cnt;
        visited[a][b][0] = visited[a][b][1] = visited[a][b][2] = true;
        path = 0;
    }
    else {
        mx[a][b][path] = cnt;
        visited[a][b][path] = true;
    }

    for (int i = 0; i < 3; ++i) {
        int ii = a + option[i].x, jj = b + option[i].y;
        if (ii >= 0 && ii < N && jj >= 0 && jj < M) {
            int max_val = max(mx[ii][jj][0], max(mx[ii][jj][1], mx[ii][jj][2]));
            if (max_val < mx[a][b][path] + arr[ii][jj] && !visited[ii][jj][i]) {
                solve(ii, jj, mx[a][b][path] + arr[ii][jj], i);
                visited[ii][jj][path] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    arr.resize(N, vector<int>(M));
    mx.resize(N, vector<vector<int>>(M, vector<int>(3, 0)));
    visited.resize(N, vector<vector<bool>>(M, vector<bool>(3, false)));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];

    solve(0, 0, arr[0][0], 3);

    cout << max(mx[N - 1][M - 1][0], max(mx[N - 1][M - 1][1], mx[N - 1][M - 1][2])) << "\n";

    return 0;
}
