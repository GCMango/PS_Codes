#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    vector<vector<int>> arr(a.size(), vector<int>(b.size(), 0));

    for (int i = 0; i < a.size(); ++i)
        arr[i][0] = (a[i] == b[0]);
    for (int i = 0; i < b.size(); ++i)
        arr[0][i] = (a[0] == b[i]);

    int mx = 0;
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 1; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                mx = max(mx, arr[i][j]);
            }
        }
    }

    cout << mx << "\n";

    return 0;
}
