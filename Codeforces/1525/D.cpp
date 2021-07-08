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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0, arr[5000];
    bool check[5000];
    cin >> N;
    vector<int> ones;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (arr[i])
            ones.push_back(i);
    }
    while (1) {
        bool all_empty = true;
        for (int i = 0; i < ones.size(); ++i) {
            if (!arr[ones[i]]) continue;
            all_empty = false;
            int x = ones[i];
            check[x] = true;
            cout << x << ' ';
            bool l = true, r = true;
            for (int j = 1; j < N; ++j) {
                if (x - j >= 0 && l) {
                    if (arr[x - j])
                        l = false;
                    else if (!check[x - j]) {
                        swap(arr[x], arr[x - j]);
                        sum += j;
                        break;
                    }
                }
                else if (x + j < N && r) {
                    if (arr[x + j])
                        r = false;
                    else if (!check[x + j]) {
                        swap(arr[x], arr[x + j]);
                        sum += j;
                        break;
                    }
                }
            }
        }
        if (all_empty) break;
    }
    cout << sum << '\n';

    return 0;
}
