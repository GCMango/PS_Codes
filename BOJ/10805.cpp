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

int dp[55][55];

int dfs(int h1, int w1, int h2, int w2) {
    if (!h2 && !w2 && dp[h1][w1]) return dp[h1][w1];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h1, h2, w1, w2;
    cin >> h1 >> w1 >> h2 >> w2;
    cout << dfs(h1, w1, h2, w2) << '\n';

    return 0;
}
