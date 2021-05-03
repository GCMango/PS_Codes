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
    vector<vector<int>> arr(N, vector<int>(N));
    int i = 0, j = 0, ri = 0, rj = 0, cnt = 0;
    for (int k = 0; k < N; ++k) {
        i = ri, j = rj;
        int n = input[k];
        arr[i][j] = n;
        cnt++;
        i++; ri++;
        if (cnt == n) { cnt = 0; continue; }
        int jj;
        for (jj = 0; jj <= j; ++jj) {
            if (cnt == n) break;
            arr[i][jj] = n;
            cnt++;
        }
        ri = i, rj = jj;
        i++; j = 0;
        for (i; i < N; ++i) {
            if (cnt == n) break;
            arr[i][j] = n;
            i++; cnt++;
        }
        cnt = 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << arr[i][j] << ' ';
        cout << "\n";
    }

    return 0;
}
