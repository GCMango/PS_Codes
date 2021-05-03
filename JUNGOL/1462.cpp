#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int INF = 1e9;

int N, M, result = 0;
vector<vector<char>> input;
vector<vector<int>> arr;

void solve(int y, int x) {
    if (input[y][x] == 'W') return;

    queue<p> que;
    que.push({x, y});
    arr[y][x] = 0;
    vector<p> options{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    while (!que.empty()) {
        p cur = que.front();
        que.pop();
        if (input[cur.y][cur.x]  == 'W') continue;
        for (int i = 0; i < 4; ++i) {
            int yy = cur.y + options[i].y, xx = cur.x + options[i].x;
            if (yy < 0 || yy >= N || xx < 0 || xx >= M) continue;
            if (arr[yy][xx] > arr[cur.y][cur.x] + 1 && input[yy][xx] == 'L') {
                arr[yy][xx] = arr[cur.y][cur.x] + 1;
                que.push({xx, yy});
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] != INF)
                result = max(result, arr[i][j]);
            arr[i][j] = INF;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    input.resize(N, vector<char>(M));
    arr.resize(N, vector<int>(M, INF));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> input[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            solve(i, j);

    cout << result << "\n";

    return 0;
}
