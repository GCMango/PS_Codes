#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, sum = 0, result = 1e9;
    cin >> N >> M;
    vector<p> input(N);
    for (int i = 0; i < N; ++i) cin >> input[i].x;
    for (int i = 0; i < N; ++i) { cin >> input[i].y; sum += input[i].y; }

    vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (j >= input[i - 1].y)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - input[i - 1].y] + input[i - 1].x);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for (int i = 0; i <= sum; ++i)
        if (dp[N][i] >= M)
            result = min(result, i);

    cout << result << "\n";

    return 0;
}
