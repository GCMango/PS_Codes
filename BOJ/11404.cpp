#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) arr[i][i] = 0;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a - 1][b - 1] = min(arr[a - 1][b - 1], c);
    }

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (arr[i][j] == INF ? 0 : arr[i][j]) << ' ';
        }
        cout << "\n";
    }

    return 0;
}
