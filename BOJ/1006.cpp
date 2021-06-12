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

int N, W, arr[20002], dp[20002][3];

int dfs(int cur, int with, vector<bool> check) {
    check[cur] = true;
    int res = 0, pos = cur < N ? cur + N : cur - N;
    if (!with) {
        if (!check[pos] && arr[cur] + arr[pos] <= W) {
            cout << arr[cur] << ' ' << arr[pos] << " 1\n";
            res = max(res, dfs(pos, cur, check) + 1);
        }
        pos = (cur - 1) % N == 0 ? cur - 1 + N : cur - 1;
        if (!check[pos] && arr[cur] + arr[pos] <= W) {
            cout << arr[cur] << ' ' << arr[pos] << " 2\n";
            res = max(res, dfs(pos, cur, check) + 1);
        }
        pos = cur % N == 0 ? cur - N + 1 : cur + 1;
        if (!check[pos] && arr[cur] + arr[pos] <= W) {
            cout << arr[cur] << ' ' << arr[pos] << " 3\n";
            res = max(res, dfs(pos, cur, check) + 1);
        }
    }
    for (int i = 1; i <= N * 2; ++i)
        if (i != cur && !check[i])
            res = max(res, dfs(i, 0, check));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> W;
        for (int i = 1; i <= N * 2; ++i) cin >> arr[i];
        int res = 0;
        vector<bool> check(20002);
        for (int i = 1; i <= N * 2; ++i)
            res = max(res, dfs(i, 0, check));
        cout << N * 2 - res << '\n';
    }

    return 0;
}
