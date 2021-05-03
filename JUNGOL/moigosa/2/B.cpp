#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k, cnt = 0;
        cin >> n >> k;
        vector<bool> light(n + 1, false);
        light[0] = true;
        for (int i = 0; i < k; ++i) {
            bool all_on = true;
            for (int i = n; i > 0; --i) {
                if (light[i - 1])
                    light[i] = !light[i];
                if (!light[i])
                    all_on = false;
            }
            cnt++;
            if (all_on)
                break;
        }
        bool all_on = true;
        for (int i = 1; i <= n; ++i)
            if (!light[i])
                all_on = false;
        if (k % (cnt + 1) == cnt && all_on) cout << "ON\n";
        else cout << "OFF\n";
    }

    return 0;
}
