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

void solve() {
    int N, input[2000];
    pll dp[2000][2];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> input[i];
    dp[0][1] = {input[0], 1};
    for (int i = 1; i < N; ++i) {

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}