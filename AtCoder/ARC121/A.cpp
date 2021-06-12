#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    pii a[1000000], b[1000000];
    vector<pii> arr;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i].x >> b[i].x;
        a[i].y = b[i].y

    sort(a, a + N);
    sort(b, b + N);
    arr.push_back({abs(a[0] - a[N - 1]), 1});
    arr.push_back({abs(b[0] - b[N - 1]), 2});
    arr.push_back({abs(a[0] - a[N - 2]), 1});
    arr.push_back({abs(b[0] - b[N - 2]), 2});
    arr.push_back({abs(a[1] - a[N - 1]), 1});
    arr.push_back({abs(b[1] - b[N - 1]), 2});
    sort(all(arr), [&](pii &p, pii &q) {
        return p.x > q.x;
    });
    if (arr[0].y == arr[1].y)
        cout << arr[2].x;
    else
        cout << arr[1].x;
    cout << '\n';

    return 0;
}

