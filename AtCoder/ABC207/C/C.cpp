#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cnt = 0;
    pdd arr[2000];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        switch (t) {
            case 1:
                arr[i].x = l, arr[i].y = r;
                break;
            case 2:
                arr[i].x = l, arr[i].y = r - 0.5;
                break;
            case 3:
                arr[i].x = l + 0.5, arr[i].y = r;
                break;
            case 4:
                arr[i].x = l + 0.5, arr[i].y = r - 0.5;
        }
        cerr << arr[i].x << ' ' << arr[i].y << '\n';
    }
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if ((arr[i].x <= arr[j].x && arr[j].x <= arr[i].y) || (arr[j].x <= arr[i].x && arr[i].x <= arr[j].y)) cnt++;
    cout << cnt << '\n';

    return 0;
}
