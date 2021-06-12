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

int N, M, dp[10001][101];

int dfs(int a, int b) {
    if (a % b == 0 || b % a == 0) return max(a, b) / min(a, b);
    if (dp[a][b]) return dp[a][b];
    int ans = a * b;
    if (a >= b * 3) ans = min(ans, dfs(a - b, b) + 1);
    else if (b >= a * 3) ans = min(ans, dfs(a, b - a) + 1);
    else {
        for (int i = 1; i < a; ++i)
            ans = min(ans, dfs(i, b) + dfs(a - i, b));
        for (int i = 1; i < b; ++i)
            ans = min(ans, dfs(a, i) + dfs(a, b - i));
    }
    return dp[a][b] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cout << dfs(N, M) << '\n';

    return 0;
}
