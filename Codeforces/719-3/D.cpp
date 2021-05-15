#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define INF 1000000002
#define setting ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

#define MAX 1000010



ll t,n;

int main()
{
    setting;
    cin>>t;
    while(t--){
        cin>>n;
        map<ll, ll> m;
        vector<ll> v;
        ll a[200001]={},cnt=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i]; a[i]= a[i]-i;
            if(!m[a[i]]) v.push_back(a[i]);
            m[a[i]]++;
        }
        for(ll i:v){
            cnt += m[i]*(m[i]-1)/2;
        }
        cout << cnt << endl;
    }
}
