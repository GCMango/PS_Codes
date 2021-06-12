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

const int MXN = 3003;

int N, ca, cb, arr[MXN], dp[MXN], sum[MXN][MXN];

int dfs(int cur) {
    if (cur >= N) return 0;
    if (dp[cur]) return dp[cur];

    int ans = sum[cur][N];
    for (int i = cur + 1; i <= N; ++i) {
        int comp = dfs(i) + cb;
        int pos = lower_bound(arr, arr + N, (arr[cur] + arr[i]) / 2) - arr;
        int mn = min(sum[cur][pos - 1] + sum[i][pos], sum[cur][pos] + sum[i][pos + 1]);
        if (pos - 2 >= cur)
            mn = min(mn, sum[cur][pos - 2] + sum[i][pos - 1]); //??????????
        if (pos + 2 <= i)
            mn = min(mn, sum[cur][pos + 1] + sum[i][pos + 2]); //??????????
        comp += mn;
        ans = min(ans, comp);
    }

    return dp[cur] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    cin >> ca >> cb;
    sort(arr + 1, arr + N + 1);
    for (int i = 0; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j)
            sum[i][j] = sum[i][j - 1] + (arr[j] - arr[i]) * ca;
        for (int j = i - 1; j >= 0; --j)
            sum[i][j] = sum[i][j + 1] + (arr[i] - arr[j]) * ca;
    }
    cout << dfs(0) << '\n';

    return 0;
}

// ||||||||||||||||||||||||||||||||||||||||||||||||||
//          2                   1         1         1
