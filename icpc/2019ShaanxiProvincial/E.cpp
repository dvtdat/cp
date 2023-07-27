//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

const ll infLL = 2e18 + 7;
const int inf = 2e9 + 7;
const int maxN = 200010;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;

int n,k;
bool check(int L,string s,int k){
    int d=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='0')  continue;
        else if (s[i]=='1') i+=L-1,d++;
    }
    return d<=k;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.inp", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
    int ans;
    while (test--){
        cin>>n>>k;
        string s;
        cin>>s;
        int l=1,r=n;
        while (l<=r){
            int mid=(l+r)/2;
            if (check(mid,s,k)){
                //cout<<mid<<'\n';
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
            cout<<ans<<'\n';
    }

}

//         _       _      _
//        | |     | |    | |
//      __| |_   _| |_ __| |
//     / _` \ \ / / __/ _` |
//    | (_| |\ V /| || (_| |
//     \__,_| \_/  \__\__,_|
//
//

