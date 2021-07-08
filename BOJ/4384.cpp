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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, arr[101], dp[101][101];
    memset(dp, 0, sizeof(dp));
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i / 2; ++j) {
            int a = j, b = i - j;
            a
            dp[a][b] = min()
        }
    }

    return 0;
}
