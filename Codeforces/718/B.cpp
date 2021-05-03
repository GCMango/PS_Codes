#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

bool compare(::p &p, ::p &q) { return p.x < q.x; }
bool compare2(::p &p, ::p &q) { return p.y < q.y || (p.y == q.y && p.x < q.x); }

void solve() {
    int N, M, sum = 0;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    vector<p> mins;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            mins.push_back({arr[i][j], i});
        }
    }
    sort(mins.begin(), mins.end(), compare);
    sort(mins.begin(), mins.begin() + M, compare2);
    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        int k = mins[cnt].y;
        vector<int> nums = arr[k];
        for (int j = 0; j < M; ++j) arr[k][j] = 0;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < M; ++j) {
            if (nums[j] == mins[cnt].x) {
                arr[k][cnt] = mins[cnt].x;
                nums[j] = -1;
                cnt++;
            }
            if (cnt >= M) break;
        }
        int r = 0;
        for (int j = 0; j < M; ++j) {
            if (nums[j] == -1) continue;
            while (arr[k][r] != 0) r++;
            arr[k][r] = nums[j];
        }
        if (cnt >= M) break;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << arr[i][j] << ' ';
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
