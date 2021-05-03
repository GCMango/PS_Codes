#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> input(N);
    for (int i = 0; i < N; ++i) cin >> input[i];
    sort(input.begin(), input.end());
    
    int M = input[N - 1] - input[0], mx = 1;
    vector<vector<int>> dp(M + 1, vector<int>(N, 0));
    for (int i = 1; i <= M; ++i) dp[i][0] = 1;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j < N; ++j) {
            bool bl = false;
            for (int k = 0; k < j; ++k) {
                if (input[j] - input[k] == i) {
                    dp[i][j] = dp[i][k] + 1;
                    bl = true;
                }
            }
            if (!bl)
                dp[i][j] = dp[i][j - 1];
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx << "\n";

    return 0;
}
