#include <bits/stdc++.h>

int arr[100001];
int aa[100001], at[100001], ac[100001];
int ba[100001], bt[100001], bc[100001];

void init(std::string a, std::string b) {
    for (int i = 0; i < a.size(); ++i) {
        arr[i + 1] = arr[i];
        aa[i + 1] = aa[i], at[i + 1] = at[i], ac[i + 1] = ac[i];
        ba[i + 1] = ba[i], bt[i + 1] = bt[i], bc[i + 1] = bc[i];
        if (a[i] != b[i]) arr[i + 1]++;
        switch (a[i]) {
            case 'A':
                aa[i + 1]++;
                break;
            case 'T':
                at[i + 1]++;
                break;
            case 'C':
                ac[i + 1]++;
        }
        switch (b[i]) {
            case 'A':
                ba[i + 1]++;
                break;
            case 'T':
                bt[i + 1]++;
                break;
            case 'C':
                bc[i + 1]++;
        }
    }
}

int get_distance(int x, int y) {
    int ans = arr[y + 1] - arr[x];
    if (aa[y + 1] - aa[x] != ba[y + 1] - ba[x] || at[y + 1] - at[x] != bt[y + 1] - bt[x] || ac[y + 1] - ac[x] != bc[y + 1] - bc[x])
        return -1;
    return ans - 1;
	return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b; cin >> a >> b;
    init(a, b);
    int x, y;
    cin >> x >> y;
    cout << get_distance(x, y) << '\n';

    return 0;
}
