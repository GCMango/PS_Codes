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

const int MXN = 16;

int N, arr[MXN][MXN], dp[MXN][1 << MXN];

int dfs(int cur, int check) {
    if (check == (1 << N) - 1) {
        if (arr[cur][0]) return arr[cur][0];
        return 1e9;
    }
    if (dp[cur][check]) return dp[cur][check];
    int ans = 1e9;
    for (int i = 0; i < N; ++i)
        if (!(check & (1 << i)) && arr[cur][i])
            ans = min(ans, dfs(i, check | (1 << i)) + arr[cur][i]);
    return dp[cur][check] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    cout << dfs(0, 1) << '\n';

    return 0;
}
