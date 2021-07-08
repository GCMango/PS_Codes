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
        int N;
        cin >> N;
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < N; ++i) {
            int n;
            cin >> n;
            if (n % 2 == 0) even.push_back(n);
            else odd.push_back(n);
        }
        cout << "\n";

        for (int i = 0; i < odd.size(); ++i) cout << odd[i] << ' ';
        for (int i = 0; i < even.size(); ++i) cout << even[i] << ' ';
    }

    return 0;
}
