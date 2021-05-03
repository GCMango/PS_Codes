#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0;
    cin >> N;
    vector<int> input(6);
    vector<int> arr(6, 0);
    vector<int> mon{500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 6; ++i) cin >> input[i];

    for (int i = 5; i > 0; --i) {
        int left = N % mon[i - 1];
        arr[i] = left / mon[i]; input[i] -= left / mon[i]; N -= left;
        sum += left / mon[i];
        if (N == 0) break;
        int mod = mon[i - 1] / mon[i];
        left = input[i] - input[i] % mod;
        arr[i] += left; input[i] -= left; N -= left * mon[i];
        sum += left;
        if (N == 0) break;
    }
    arr[0] = N / mon[0];
    sum += arr[0];
    /*arr[5] = N % 5;
    input[5] -= N % 5;
    N -= N % 5;*/

    cout << sum << "\n";
    for (int i = 0; i < 6; ++i) cout << arr[i] << ' ';
    cout << "\n";

    return 0;
}
