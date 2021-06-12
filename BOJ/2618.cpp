#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

struct Dist {
    int n;
    p a;
    p b;
    int last;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    p a, b;
    a.x = a.y = 0;
    b.x = b.y = N - 1;
    cin >> N >> M;
    vector<p> input(M);
    vector<vector<Dist>> dp(2, vector<Dist>(M));
    for (int i = 0; i < M; ++i) {
        cin >> input[i].x >> input[i].y;
        input[i].x--; input[i].y--;
    }

    dp[0][0] = {abs(a.x - input[0].x) + abs(a.y - input[0].y), {input[0].x, input[0].y}, {N - 1, N - 1}, -1};
    dp[1][0] = {abs(b.x - input[0].x) + abs(b.y - input[0].y), {0, 0}, {input[0].x, input[0].y}, -1};

    for (int i = 1; i < M; ++i) {
        int a1 = abs(dp[i - 1][0].a.x - input[i].x) + abs(dp[i - 1][0].a.y - input[i].y);
        int b1 = abs(dp[i - 1][0].b.x - input[i].x) + abs(dp[i - 1][0].b.y - input[i].y);
        int a2 = abs(dp[i - 1][1].a.x - input[i].x) + abs(dp[i - 1][1].a.y - input[i].y);
        int b2 = abs(dp[i - 1][1].b.x - input[i].x) + abs(dp[i - 1][1].b.y - input[i].y);

        if (a1 < a2) {
            dp[i][0].n = dp[i - 1][0].n + a1;
            dp[i][0].a = input[i];
            dp[i][0].b = dp[i - 1][0].b;
        }
        else {
            dp[i][0].n = dp[i - 1][1].n + a2;
            dp[i][0].a = input[i];
            dp[i][0].b = dp[i - 1][1].b;
        }

        if (b1 < b2) {
            dp[i][1].n = dp[i - 1][0].n + b1;
            dp[i][1].a = dp[i - 1][0].a;
            dp[i][1].b = input[i];
        }
        else {
            dp[i][1].n = dp[i - 1][1].n + b2;
            dp[i][1].a = dp[i - 1][1].a;
            dp[i][1].b = input[i];
        }
    }

    cout << min(dp[M - 1][0].n, dp[M - 1][1].n) << "\n";

    return 0;
}
