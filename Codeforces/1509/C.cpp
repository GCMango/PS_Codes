#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll sum = 0, min_abs = 1e9;
    cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int front = 0, back = 0;
    for (int i = 1; i < N; ++i) {
        if (arr[i] - arr[i - 1] < min_abs) {
            min_abs = arr[i] - arr[i - 1];
            front = i - 1;
            back = i;
        } 
    }
    for (int i = 0; i < N; ++i) {
        sum += (arr[back] - arr[front]);
        if (front == 0) back++;
        else if (back == N - 1) front--;
        else if (front + 1 > N - back) front--;
        else if (front + 1 < N - back) back++;
        else if (arr[front] - arr[front - 1] < arr[back + 1] - arr[back]) front--;
        else back++;
        if (front < 0 || back >= N) break;
    }

    cout << sum << "\n";

    return 0;
}

// 1 3 3 3 6 6
// 69 104 6589 889921234 943872923 1000000000
