#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

bool compare(::p &p, ::p &q) { return p.x < q.x; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0;
    cin >> N;
    vector<p> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i].x >> arr[i].y;
    sort(arr.begin(), arr.end(), compare);
    int x = arr[0].x, y = arr[0].y;
    for (int i = 0; i < N; ++i) {
        if (arr[i].x <= y)
            y = max(y, arr[i].y);
        else {
            sum += y - x;
            x = arr[i].x;
            y = arr[i].y;
        }
    }
    sum += y - x;

    cout << sum << "\n";

    return 0;
}
