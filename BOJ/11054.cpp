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
    vector<vector<int>> arr(N, vector<int>(2, 1));
    for (int i = 0; i < N; ++i) cin >> input[i];

    int mx = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (input[j] < input[i] && arr[j][0] + 1 > arr[i][0])
                arr[i][0] = arr[j][0] + 1;
            else if (input[j] > input[i]) {
                if (arr[j][0] + 1 > arr[i][1])
                    arr[i][1] = arr[j][0] + 1;
                if (arr[j][1] + 1 > arr[i][1])
                    arr[i][1] = arr[j][1] + 1;
            }
            mx = max(mx, max(arr[i][0], arr[i][1]));
        }
    }

    cout << mx << "\n";

    return 0;
}

