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
        int a, b;
        cin >> a >> b;
        cout << "\n";
        if (b * 2 + 1 > a) {
            cout << -1;
            continue;
        }
        vector<int> arr;
        vector<int> check(a + 1, 0);
 
        int num = a % 2 == 0 ? a / 2 : a / 2 + 1;
 
        for (int i = 0; i < b * 2; i += 2) {
            arr.push_back(i / 2 + 1);
            arr.push_back(i / 2 + 1 + num);
            check[i / 2 + 1] = 1;
            check[i / 2 + 1 + num] = 1;
        }
 
        for (int i = a; i > 0; --i)
            if (check[i] == 0)
                arr.push_back(i);
 
        for (int i = 0; i < a; ++i)
            cout << arr[i] << ' ';
    }

    return 0;
}
