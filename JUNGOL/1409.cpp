#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, M, mn = 1e9;
vector<vector<bool>> visited;
vector<int> arr;

void solve(int a, int b, int cur, int cnt) {
    if (cnt >= mn) return;
    if (cur >= M) {
        mn = min(mn, cnt - 1);
        return;
    }
    if (a == arr[cur] || b == arr[cur]) {
        cur++;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                visited[i][j] = false;
    }
    if (a - 1 >= 0) solve(a - 1, b, cur, cnt + 1);
    if (a + 1 < b) solve(a + 1, b, cur, cnt + 1);
    if (b - 1 > a) solve(a, b - 1, cur, cnt + 1);
    if (b + 1 < N) solve(a, b + 1, cur, cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> N >> a >> b >> M;
    a--; b--;
    arr.resize(M);
    visited.resize(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) cin >> arr[i];

    solve(a, b, 0, 0);

    cout << mn << "\n";

    return 0;
}
