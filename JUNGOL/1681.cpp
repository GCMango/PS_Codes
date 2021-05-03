#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int INF = 1e9;

int N, ans = INF;
vector<vector<int>> arr;

void solve(int cur, int cost, vector<int> visit) {
    visit[cur] = 1;
    if (cost > ans) return;
    bool last = true;

    for (int i = 0; i < visit.size(); ++i) {
        if (visit[i] == 0) {
            last = false;
            if (arr[cur][i] != 0)
                solve(i, cost + arr[cur][i], visit);
        }
    }

    if (last && arr[cur][0] != 0) ans = min(ans, cost + arr[cur][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N, vector<int>(N));
    vector<int> visit(N, 0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];

    solve(0, 0, visit);
    cout << ans << "\n";

    return 0;
}
