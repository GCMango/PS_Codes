#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
vector<vector<int>> dp;
vector<bool> expt;

int solve(int cur, int cou, int mon) {
    if (cur > N) return mon;
    if (dp[cur][cou] != 1e9) return dp[cur][cou] + mon;
    if (expt[cur]) return solve(cur + 1, cou, mon);

    int result = 1e9;
    if (cou >= 3)
        result = min(result, solve(cur + 1, cou - 3, mon));

    result = min(result, solve(cur + 1, cou, mon + 10000));
    result = min(result, solve(cur + 3, cou + 1, mon + 25000));
    result = min(result, solve(cur + 5, cou + 2, mon + 37000));

    dp[cur][cou] = result - mon;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    dp.resize(N + 1, vector<int>(N + 1, 1e9));
    expt.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int n; cin >> n;
        expt[n] = true;
    }

    cout << solve(1, 0, 0) << '\n';

    return 0;
}

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
//         0   0 0         0  0   
// 
