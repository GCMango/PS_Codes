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

    int N, K; cin >> N >> K;
    int fibo[41], sum[41], dp[41];
    fibo[0] = fibo[1] = sum[0] = dp[0] = dp[1] = 1, sum[1] = dp[2] = 2;
    for (int i = 2; i <= 40; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        sum[i] = sum[i - 1] + fibo[i];
    }
    for (int i = 3; i <= N; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + sum[i - 2] + sum[i - 3];
    cout << dp[K] * fibo[N - K] + dp[N - K + 1] * fibo[K - 1] - fibo[K - 1] * fibo[N - K] << '\n';

    return 0;
}
