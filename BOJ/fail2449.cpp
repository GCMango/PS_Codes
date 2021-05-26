#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, K, b, dp[201][201][21];
vector<int> bulb{0};

int dfs(int s, int e, int c) {
    if (s == e)
        return dp[s][e][c] = (bulb[s] != c);
    if (s > e) return 1000;
    if (dp[s][e][c])
        return dp[s][e][c];
    int ans = 1e9;
    for (int i = s; i < e; ++i)
        ans = min(ans, dfs(s, i, c) + dfs(i + 1, e, c));
    for (int i = 1; i <= K; ++i) {
        int d = dfs(s + 1, e - 1, i), r;
        if (bulb[s] == bulb[e]) 
            r = d + 2 - (bulb[s] == i) * 2;
        else
            r = d + 2 - (bulb[s] == i || bulb[e] == i);
        ans = min(ans, r + (i != c));
    }
    dp[s][e][c] = ans;
    return dp[s][e][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n != bulb[bulb.size() - 1])
            bulb.push_back(n);
    }

    b = bulb.size() - 1;

    int ans = 1e9;
    for (int i = 1; i <= K; ++i)
        ans = min(ans, dfs(1, b, i));
    cout << ans << '\n';

    return 0;
}

