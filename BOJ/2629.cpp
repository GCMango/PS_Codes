#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, sum = 0;
vector<bool> check;
vector<int> arr;

void solve(int cur, int sum) {
    if (sum >= check.size()) return;
    if (cur >= 0) check[cur] = true;
    for (int i = 0; i < N; ++i) {
        if (i == cur) continue;
        if (sum + arr[i] < check.size() && check[sum + arr[i]] == false)
            solve(i, sum + arr[i]);
        if (sum - arr[i] >= 0 && !check[sum - arr[i]] == false)
            solve(i, sum - arr[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    check.resize(sum + 1, false);
    solve(-1, 0);

    for (int i = 0; i <= sum; ++i) cout << check[i] << ' ';
    cout << "\n";

    int M;
    cin >> M;
    while (M--) {
        int n;
        cin >> n;
        cout << (check[n] ? "Y" : "N") << "\n";
    }

    return 0;
}
