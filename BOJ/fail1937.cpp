#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, mx_val = 0;
vector<vector<int>> arr;
vector<vector<int>> mx;
vector<p> option{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(int i, int j, int cnt) {
    mx[i][j] = cnt;
    mx_val = max(mx_val, mx[i][j]);

    for (int k = 0; k < 4; ++k) {
        int ii = i + option[k].x, jj = j + option[k].y;
        if (ii < 0 || ii >= N || jj < 0 || jj >= N) continue;
        if (arr[ii][jj] > arr[i][j] && mx[ii][jj] < cnt + 1)
            solve(ii, jj, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N, vector<int>(N));
    mx.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (mx[i][j] == 0)
                solve(i, j, 1);

    cout << mx_val << "\n";

    return 0;
}
