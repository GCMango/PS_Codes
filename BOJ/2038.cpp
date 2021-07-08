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

int N, arr[(int)1e7 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int idx = 1, cur = 1;
    arr[1] = 1;
    while (cur < N) {
        idx++;
        arr[idx] = 1 + arr[idx - arr[arr[idx - 1]]];
        cur += arr[idx];
    }
    cout << idx << '\n';

    return 0;
}
