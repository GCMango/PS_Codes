#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    deque<int> nums(n);
    vector<int> query(m);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = 0; i < m; ++i) cin >> query[i];
 
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (nums[j] == query[i]) {
                int r = nums[j];
                cout << j + 1 << ' ';
                nums.erase(nums.begin() + j);
                nums.push_front(r);
                break;
            }
        }
    }

    return 0;
}
