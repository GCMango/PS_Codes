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
    cin >> N >> M;
    vector<int> input(N);
    vector<int> dp(N, 0);
    for (int i = 0; i < N; ++i) cin >> input[i];

    stack<int> st;
    for (int i = 1; i < N; ++i) {
        if (input[i] == input[i - 1])
            dp[i] = dp[i - 1];
        else {
            if (!st.empty() && input[i] == st.top()) {
                dp[i] = dp[i - 1] + 1;
                st.pop();
            }
            else {
                st.push(input[i - 1]);
                dp[i] = dp[i - 1];
            }
        }
    }

    int result = dp[N - 1];
    while (!st.empty()) {
        result++;
        st.pop();
    }

    cout << result << "\n";

    return 0;
}
