#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, mx = 0;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            mx = max(mx, arr[i][j]);
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (arr[i][j] == 0 || arr[i - 1][j - 1] == 0) continue;
            bool squ = true;
            int k;
            for (k = 1; k <= arr[i - 1][j - 1]; k++)
                if (arr[i][j - k] == 0 || arr[i - k][j] == 0)
                    break;
            if (squ) arr[i][j] += k - 1;
            mx = max(mx, arr[i][j]);
        }
    }

    cout << mx * mx << "\n";

    return 0;
}
