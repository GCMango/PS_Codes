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
        int n, num = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];
        cout << "\n";
 
        for (int i = 0; i < n; ++i) {
            switch (arr[i]) {
                case 1:
                    num++;
                    break;
                case 3:
                    num++;
            }
        }
 
        cout << num;
    }

    return 0;
}
