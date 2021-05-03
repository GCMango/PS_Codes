#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> input(N);
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) cin >> input[i];

    for (int i = 0; i < N; ++i) dp[i][i] = 1;
    for (int i = 0; i < N - 1; ++i) dp[i][i + 1] = (input[i] == input[i + 1]);

    for (int len = 3; len <= N; ++len) {
        for (int i = 0; i < N - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = (input[i] == input[j] && dp[i + 1][j - 1]);
        }
    }

    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << dp[a][b] << "\n";
    }

    return 0;
}
