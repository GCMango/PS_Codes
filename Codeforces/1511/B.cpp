#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "\n";
 
        string str_a = "", str_b = "", str_c = "";
        for (int i = 0; i < c; ++i) str_c += '1';
        for (int i = 0; i < a - c + 1; ++i) str_a += '1';
        for (int i = 0; i < b - c + 1; ++i) str_b += '1';
        int64_t ans_a = atoi(str_a.c_str()) * atoi(str_c.c_str());
        int64_t ans_b = atoi(str_b.c_str()) * atoi(str_c.c_str());
        ans_b += atoi(str_c.c_str());
        cout << ans_a << ' ' << ans_b;
    }

    return 0;
}
