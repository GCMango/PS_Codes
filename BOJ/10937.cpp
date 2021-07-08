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

const int MXN = 11;
map<string, int> mp;
int N, dp[MXN * MXN][1 << MXN];
char arr[MXN][MXN];

int dfs(int n, int chk) {
    if (n >= N * N) return 0;
    int &ret = dp[n][chk];
    if (ret != -1) return ret;
    ret = dfs(n + 1, chk >> 1);
    if (chk & 1) return ret;
    int i = n / N, j = n % N;
    if (j < N - 1 && !(chk & (1 << 1))) {
        char a = arr[i][j], b = arr[i][j + 1];
        if (a > b) swap(a, b);
        string s({a, b});
        int comp = (b == 'F' ? 0 : mp[s]);
        ret = max(ret, dfs(n + 2, chk >> 2) + comp);
    }
    if (i < N - 1) {
        char a = arr[i][j], b = arr[i + 1][j];
        if (a > b) swap(a, b);
        string s({a, b});
        int comp = (b == 'F' ? 0 : mp[s]);
        ret = max(ret, dfs(n + 1, (chk >> 1) | (1 << (N - 1))) + comp);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    mp["AA"] = 100, mp["AB"] = 70, mp["AC"] = 40;
    mp["BB"] = 50, mp["BC"] = 30, mp["CC"] = 20;
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    cout << dfs(0, 0) << '\n';

    return 0;
}

