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
    vector<p> arr(N, {1, -1});
    for (int i = 0; i < N; ++i) cin >> input[i];

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (input[j] < input[i] && arr[j].x + 1 > arr[i].x) {
                arr[i].x = arr[j].x + 1;
                arr[i].y = j;
            }
        }
    }

    int max_idx = -1, max_val = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i].x > max_val) {
            max_idx = i;
            max_val = arr[i].x;
        }
    }

    vector<int> result;
    while (max_idx != -1) {
        result.push_back(input[max_idx]);
        max_idx = arr[max_idx].y;
    }

    cout << max_val << "\n";
    for (int i = result.size() - 1; i >= 0; --i)
        cout << result[i] << ' ';
    cout << "\n";

    return 0;
}
