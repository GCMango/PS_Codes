#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int N;
    cin >> N;
    vector<int> input(N + 1);
    vector<p> arr(N + 1);
    vector<p> result(N + 1, {1, -1});

    for (int i = 1; i <= N; ++i) {
        int n;
        cin >> n;
        input[n] = i;
    }
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].x;
        arr[i].y = input[arr[i].x];
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j < i; ++j) {
            if (arr[j].y < arr[i].y && result[j].x + 1 > result[i].x) {
                result[i].x = result[j].x + 1;
                result[i].y = j;
            }
        }
    }

    int mx_idx = -1, mx_val = 0;
    for (int i = 1; i <= N; ++i) {
        if (result[i].x > mx_val) {
            mx_val = result[i].x;
            mx_idx = i;
        }
    }

    cout << result[mx_idx].x << "\n";

    vector<int> output;
    int cur = mx_idx;
    while (cur != -1) {
        output.push_back(arr[cur].x);
        cur = result[cur].y;
    }

    sort(output.begin(), output.end());
    for (int i = 0; i < output.size(); ++i)
        cout << output[i] << ' ';
    cout << "\n";
 
    return 0;
}
